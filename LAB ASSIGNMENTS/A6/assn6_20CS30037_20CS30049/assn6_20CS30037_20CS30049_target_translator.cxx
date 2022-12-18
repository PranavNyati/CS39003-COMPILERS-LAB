/*
    Compilers Lab Assignment - 6
    Group Members :-
        Pranav Nyati - 20CS30037
        Shreyas Jena - 20CS30049
*/

// cxx file defining functionalities for machine-dependent translation from TAC to x86-64 ASM
#include "assn6_20CS30037_20CS30049_translator.h"
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

// External variables
extern SymbolTable SymTbl_Global;
extern SymbolTable *SymTbl;
extern QuadArray QuadList;

// Declare global variables
vector<string> const_strs;
map<int, string> labels;
stack<pair<string, int>> parameters;
int labelCount = 0;
string is_running = "";
string filename;

// Prints the global information to the assembly file
void printGlobal(ofstream &asm_file)
{
    for (auto it = SymTbl_Global.symbols.begin(); it != SymTbl_Global.symbols.end(); it++)
    {
        Symbol *sym = *it;
        if (sym->type.type == CHAR && sym->name[0] != 't')
        {
            if (sym->init_val != NULL)
            {
                asm_file << "\t.globl\t" << sym->name << endl;
                asm_file << "\t.data" << endl;
                asm_file << "\t.type\t" << sym->name << ", @object" << endl;
                asm_file << "\t.size\t" << sym->name << ", 1" << endl;
                asm_file << sym->name << ":" << endl;
                asm_file << "\t.byte\t" << sym->init_val->char_ << endl;
            }
            else
                asm_file << "\t.comm\t" << sym->name << ",1,1" << endl;
        }
        else if (sym->type.type == INT && sym->name[0] != 't')
        {
            if (sym->init_val != NULL)
            {
                asm_file << "\t.globl\t" << sym->name << endl;
                asm_file << "\t.data" << endl;
                asm_file << "\t.align\t4" << endl;
                asm_file << "\t.type\t" << sym->name << ", @object" << endl;
                asm_file << "\t.size\t" << sym->name << ", 4" << endl;
                asm_file << sym->name << ":" << endl;
                asm_file << "\t.long\t" << sym->init_val->int_ << endl;
            }
            else
                asm_file << "\t.comm\t" << sym->name << ",4,4" << endl;
        }
    }
}

// Prints all the strings used in the program to the assembly file
void printStrings(ofstream &asm_file)
{
    
    asm_file << ".section\t.rodata" << endl;
    int i = 0;

    for (auto it = const_strs.begin(); it != const_strs.end(); it++)
    {
        asm_file << ".LC" << i++ << ":" << endl;
        asm_file << "\t.string " << *it << endl;
    }
}

// Generates labels for different targets of goto statements
void setLabels()
{
    int i = 0;
    for (auto it = QuadList.quads.begin(); it != QuadList.quads.end(); it++)
    {
        if (it->op == GOTO || (it->op >= GOTO_EQ && it->op <= IF_FALSE_GOTO))
        {
            int target = atoi((it->result.c_str()));
            if (!labels.count(target))
            {
                string labelName = ".L" + to_string(labelCount++);
                labels[target] = labelName;
            }
            it->result = labels[target];
        }
    }
}

// Generates the function prologue to be printed before each function
void generatePrologue(int memBind, ofstream &asm_file)
{
    int width = 16;
    asm_file << endl
          << "\t.text" << endl;
    asm_file << "\t.globl\t" << is_running << endl;
    asm_file << "\t.type\t" << is_running << ", @function" << endl;
    asm_file << is_running << ":" << endl;
    asm_file << "\tpushq\t"
          << "%rbp" << endl;
    asm_file << "\tmovq\t"
          << "%rsp, %rbp" << endl;
    asm_file << "\tsubq\t$" << (memBind / width + 1) * width << ", %rsp" << endl;
}

// Generates assembly code for a given three address quad
void quadCode(Quad quad, ofstream &asm_file)
{
    string strLabel = quad.result;
    bool hasStrLabel = (quad.result[0] == '.' && quad.result[1] == 'L' && quad.result[2] == 'C');
    string toPrint1 = "", toPrint2 = "", toPrintRes = "";
    int off1 = 0, off2 = 0, offRes = 0;

    Symbol *addr1 = SymTbl->lookup(quad.arg1);
    Symbol *addr2 = SymTbl->lookup(quad.arg2);
    Symbol *addr3 = SymTbl->lookup(quad.result);
    Symbol *glb1 = SymTbl_Global.find_glbl(quad.arg1);
    Symbol *glb2 = SymTbl_Global.find_glbl(quad.arg2);
    Symbol *glb3 = SymTbl_Global.find_glbl(quad.result);

    if (SymTbl != &SymTbl_Global)
    {
        if (glb1 == NULL)
            off1 = addr1->offset;
        if (glb2 == NULL)
            off2 = addr2->offset;
        if (glb3 == NULL)
            offRes = addr3->offset;

        if (quad.arg1[0] < '0' || quad.arg1[0] > '9')
        {
            if (glb1 != NULL)
                toPrint1 = quad.arg1 + "(%rip)";
            else
                toPrint1 = to_string(off1) + "(%rbp)";
        }
        if (quad.arg2[0] < '0' || quad.arg2[0] > '9')
        {
            if (glb2 != NULL)
                toPrint2 = quad.arg2 + "(%rip)";
            else
                toPrint2 = to_string(off2) + "(%rbp)";
        }
        if (quad.result[0] < '0' || quad.result[0] > '9')
        {
            if (glb3 != NULL)
                toPrintRes = quad.result + "(%rip)";
            else
                toPrintRes = to_string(offRes) + "(%rbp)";
        }
    }
    else
    {
        toPrint1 = quad.arg1;
        toPrint2 = quad.arg2;
        toPrintRes = quad.result;
    }

    if (hasStrLabel)
        toPrintRes = strLabel;

    if (quad.op == ASSIGN)
    {
        if (quad.result[0] != 't' || addr3->type.type == INT || addr3->type.type == POINTER)
        {
            if (addr3->type.type != POINTER)
            {
                if (quad.arg1[0] < '0' || quad.arg1[0] > '9')
                {
                    asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
                    asm_file << "\tmovl\t%eax, " << toPrintRes << endl;
                }
                else
                    asm_file << "\tmovl\t$" << quad.arg1 << ", " << toPrintRes << endl;
            }
            else
            {
                asm_file << "\tmovq\t" << toPrint1 << ", %rax" << endl;
                asm_file << "\tmovq\t%rax, " << toPrintRes << endl;
            }
        }
        else
        {
            int temp = quad.arg1[0];
            asm_file << "\tmovb\t$" << temp << ", " << toPrintRes << endl;
        }
    }
    else if (quad.op == U_MINUS)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tnegl\t%eax" << endl;
        asm_file << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if (quad.op == ADD)
    {
        if (quad.arg1[0] > '0' && quad.arg1[0] <= '9')
            asm_file << "\tmovl\t$" << quad.arg1 << ", %eax" << endl;
        else
            asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        if (quad.arg2[0] > '0' && quad.arg2[0] <= '9')
            asm_file << "\tmovl\t$" << quad.arg2 << ", %edx" << endl;
        else
            asm_file << "\tmovl\t" << toPrint2 << ", %edx" << endl;
        asm_file << "\taddl\t%edx, %eax" << endl;
        asm_file << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if (quad.op == SUB)
    {
        if (quad.arg1[0] > '0' && quad.arg1[0] <= '9')
            asm_file << "\tmovl\t$" << quad.arg1 << ", %edx" << endl;
        else
            asm_file << "\tmovl\t" << toPrint1 << ", %edx" << endl;
        if (quad.arg2[0] > '0' && quad.arg2[0] <= '9')
            asm_file << "\tmovl\t$" << quad.arg2 << ", %eax" << endl;
        else
            asm_file << "\tmovl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tsubl\t%eax, %edx" << endl;
        asm_file << "\tmovl\t%edx, %eax" << endl;
        asm_file << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if (quad.op == MULT)
    {
        if (quad.arg1[0] > '0' && quad.arg1[0] <= '9')
            asm_file << "\tmovl\t$" << quad.arg1 << ", %eax" << endl;
        else
            asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\timull\t";
        if (quad.arg2[0] > '0' && quad.arg2[0] <= '9')
            asm_file << "$" << quad.arg2 << ", %eax" << endl;
        else
            asm_file << toPrint2 << ", %eax" << endl;
        asm_file << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if (quad.op == DIV)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcltd\n\tidivl\t" << toPrint2 << endl;
        asm_file << "\tmovl\t%eax, " << toPrintRes << endl;
    }
    else if (quad.op == MOD)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcltd\n\tidivl\t" << toPrint2 << endl;
        asm_file << "\tmovl\t%edx, " << toPrintRes << endl;
    }
    else if (quad.op == GOTO)
        asm_file << "\tjmp\t" << quad.result << endl;
    else if (quad.op == GOTO_LT)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tjge\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == GOTO_GT)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tjle\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == GOTO_GTE)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tjl\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == GOTO_LTE)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tjg\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == GOTO_GTE)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tjl\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == GOTO_EQ)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        if (quad.arg2[0] >= '0' && quad.arg2[0] <= '9')
            asm_file << "\tcmpl\t$" << quad.arg2 << ", %eax" << endl;
        else
            asm_file << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tjne\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == GOTO_NEQ)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t" << toPrint2 << ", %eax" << endl;
        asm_file << "\tje\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == IF_GOTO)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t$0"
              << ", %eax" << endl;
        asm_file << "\tje\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == IF_FALSE_GOTO)
    {
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tcmpl\t$0"
              << ", %eax" << endl;
        asm_file << "\tjne\t.L" << labelCount << endl;
        asm_file << "\tjmp\t" << quad.result << endl;
        asm_file << ".L" << labelCount++ << ":" << endl;
    }
    else if (quad.op == ARR_IDX_ARG)
    {
        asm_file << "\tmovl\t" << toPrint2 << ", %edx" << endl;
        asm_file << "cltq" << endl;
        if (off1 < 0)
        {
            asm_file << "\tmovl\t" << off1 << "(%rbp,%rdx,1), %eax" << endl;
            asm_file << "\tmovl\t%eax, " << toPrintRes << endl;
        }
        else
        {
            asm_file << "\tmovq\t" << off1 << "(%rbp), %rdi" << endl;
            asm_file << "\taddq\t%rdi, %rdx" << endl;
            asm_file << "\tmovq\t(%rdx) ,%rax" << endl;
            asm_file << "\tmovq\t%rax, " << toPrintRes << endl;
        }
    }
    else if (quad.op == ARR_IDX_RES)
    {
        asm_file << "\tmovl\t" << toPrint2 << ", %edx" << endl;
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "cltq" << endl;

        if (offRes > 0)
        {
            asm_file << "\tmovq\t" << offRes << "(%rbp), %rdi" << endl;
            asm_file << "\taddq\t%rdi, %rdx" << endl;
            asm_file << "\tmovl\t%eax, (%rdx)" << endl;
        }
        else
            asm_file << "\tmovl\t%eax, " << offRes << "(%rbp,%rdx,1)" << endl;
    }
    else if (quad.op == REFERENCE)
    {
        if (off1 < 0)
        {
            asm_file << "\tleaq\t" << toPrint1 << ", %rax" << endl;
            asm_file << "\tmovq\t%rax, " << toPrintRes << endl;
        }
        else
        {
            asm_file << "\tmovq\t" << toPrint1 << ", %rax" << endl;
            asm_file << "\tmovq\t%rax, " << toPrintRes << endl;
        }
    }
    else if (quad.op == DEREFERENCE)
    {
        asm_file << "\tmovq\t" << toPrint1 << ", %rax" << endl;
        asm_file << "\tmovq\t(%rax), %rdx" << endl;
        asm_file << "\tmovq\t%rdx, " << toPrintRes << endl;
    }
    else if (quad.op == L_DEREF)
    {
        asm_file << "\tmovq\t" << toPrintRes << ", %rdx" << endl;
        asm_file << "\tmovl\t" << toPrint1 << ", %eax" << endl;
        asm_file << "\tmovl\t%eax, (%rdx)" << endl;
    }
    else if (quad.op == PARAM)
    {
        int paramSize;
        data_type t;
        if (glb3 != NULL)
            t = glb3->type.type;
        else
            t = addr3->type.type;
        if (t == INT)
            paramSize = _SIZE_INT;
        else if (t == CHAR)
            paramSize = _SIZE_CHAR;
        else
            paramSize = _SIZE_POINTER;
        stringstream ss;
        if (quad.result[0] == '.')
            ss << "\tmovq\t$" << toPrintRes << ", %rax" << endl;
        else if (quad.result[0] >= '0' && quad.result[0] <= '9')
            ss << "\tmovq\t$" << quad.result << ", %rax" << endl;
        else
        {
            if (addr3->type.type != ARRAY)
            {
                if (addr3->type.type != POINTER)
                    ss << "\tmovq\t" << toPrintRes << ", %rax" << endl;
                else if (addr3 == NULL)
                    ss << "\tleaq\t" << toPrintRes << ", %rax" << endl;
                else
                    ss << "\tmovq\t" << toPrintRes << ", %rax" << endl;
            }
            else
            {
                if (offRes < 0)
                    ss << "\tleaq\t" << toPrintRes << ", %rax" << endl;
                else
                {
                    ss << "\tmovq\t" << offRes << "(%rbp), %rdi" << endl;
                    ss << "\tmovq\t%rdi, %rax" << endl;
                }
            }
        }
        parameters.push(make_pair(ss.str(), paramSize));
    }
    else if (quad.op == CALL)
    {
        int numParams = atoi(quad.arg1.c_str());
        int totalSize = 0, k = 0;

        // We need different registers based on the parameters
        if (numParams > 6)
        {
            for (int i = 0; i < numParams - 6; i++)
            {
                string s = parameters.top().first;
                asm_file << s << "\tpushq\t%rax" << endl;
                totalSize += parameters.top().second;
                parameters.pop();
            }

            asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r9d" << endl;
            totalSize += parameters.top().second;
            parameters.pop();

            asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r8d" << endl;
            totalSize += parameters.top().second;
            parameters.pop();

            asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rcx" << endl;
            totalSize += parameters.top().second;
            parameters.pop();

            asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdx" << endl;
            totalSize += parameters.top().second;
            parameters.pop();
            
            asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rsi" << endl;
            totalSize += parameters.top().second;
            parameters.pop();

            asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdi" << endl;
            totalSize += parameters.top().second;
            parameters.pop();

        }
        else
        {
            while (!parameters.empty())
            {
                if (parameters.size() == 6)

                {
                    asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r9d" << endl;
                    totalSize += parameters.top().second;
                    parameters.pop();
                }

                else if (parameters.size() == 5)

                {
                    asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %r8d" << endl;
                    totalSize += parameters.top().second;
                    parameters.pop();
                }

                else if (parameters.size() == 4)

                {
                    asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rcx" << endl;
                    totalSize += parameters.top().second;
                    parameters.pop();
                }

                else if (parameters.size() == 3)

                {
                    asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdx" << endl;
                    totalSize += parameters.top().second;
                    parameters.pop();
                }

                else if (parameters.size() == 2)

                {
                    asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rsi" << endl;
                    totalSize += parameters.top().second;
                    parameters.pop();
                }

                else if (parameters.size() == 1)

                {
                    asm_file << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\t%rax, %rdi" << endl;
                    totalSize += parameters.top().second;
                    parameters.pop();
                }
            }
        }

        asm_file << "\tcall\t" << quad.result << endl;

        if (quad.arg2 != "")
            asm_file << "\tmovq\t%rax, " << toPrint2 << endl;

        asm_file << "\taddq\t$" << totalSize << ", %rsp" << endl;
    }

    else if (quad.op == RETURN)

    {
        if (quad.result != "")
            asm_file << "\tmovq\t" << toPrintRes << ", %rax" << endl;

        asm_file << "\tleave" << endl;
        asm_file << "\tret" << endl;
    }
}

// Main function which calls all other relevant functions for generating the target assembly code
void generateTargetCode(ofstream &asm_file)
{
    printGlobal(asm_file);
    printStrings(asm_file);
    SymbolTable *currFuncTable = NULL;
    Symbol *currFunc = NULL;
    setLabels();

    for (int i = 0; i < (int)QuadList.quads.size(); i++)
    {
        // Print the quad as a comment in the assembly file
        asm_file << "# " << QuadList.quads[i].print_quad() << endl;
        if (labels.count(i))
            asm_file << labels[i] << ":" << endl;

        // Necessary tasks for a function
        if (QuadList.quads[i].op == FUNC_BEG)
        {
            i++;
            if (QuadList.quads[i].op != FUNC_END)
                i--;
            else
                continue;

            currFunc = SymTbl_Global.find_glbl(QuadList.quads[i].result);
            currFuncTable = currFunc->nested_table;
            int takingParam = 1, memBind = 16;
            SymTbl = currFuncTable;
            
            for (int j = 0; j < (int)currFuncTable->symbols.size(); j++)
            {
                if (currFuncTable->symbols[j]->name == "RETVAL")
                {
                    takingParam = 0;
                    memBind = 0;
                    if (currFuncTable->symbols.size() > j + 1)
                        memBind = -currFuncTable->symbols[j + 1]->size;
                }
                else
                {
                    if (!takingParam)
                    {
                        currFuncTable->symbols[j]->offset = memBind;
                        if (currFuncTable->symbols.size() > j + 1)
                            memBind -= currFuncTable->symbols[j + 1]->size;
                    }
                    else
                    {
                        currFuncTable->symbols[j]->offset = memBind;
                        memBind += 8;
                    }
                }
            }
            if (memBind >= 0)
                memBind = 0;
            else
                memBind *= -1;
            is_running = QuadList.quads[i].result;
            generatePrologue(memBind, asm_file);
        }

        // Function epilogue (while leaving a function)
        else if (QuadList.quads[i].op == FUNC_END)
        {
            SymTbl = &SymTbl_Global;
            is_running = "";
            asm_file << "\tleave" << endl;
            asm_file << "\tret" << endl;
            asm_file << "\t.size\t" << QuadList.quads[i].result << ", .-" << QuadList.quads[i].result << endl;
        }

        if (is_running != "")
            quadCode(QuadList.quads[i], asm_file);
    }
}

// main function
int main(int argc, char *argv[])
{
    SymTbl = &SymTbl_Global;
    yyparse();

    filename = "assn6_20CS30037_20CS30049_" + string(argv[argc - 1]) + ".s";

    ofstream asm_file;
    asm_file.open(filename);

    QuadList.print_quads(); // Print the three address quads

    SymTbl->print_table("SymTbl.global"); // Print the symbol tables

    SymTbl = &SymTbl_Global;

    generateTargetCode(asm_file); // Generate the target assembly code

    asm_file.close();

    return 0;
}
