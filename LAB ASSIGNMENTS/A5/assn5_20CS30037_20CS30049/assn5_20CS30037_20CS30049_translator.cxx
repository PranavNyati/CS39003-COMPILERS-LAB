/* 
 Compilers Lab : Assignment 5
 Group Members:
    1. Pranav Nyati (20CS30037)
    2. Shreyas Jena (20CS30049)
*/

#include "assn5_20CS30037_20CS30049_translator.h"
#include <iomanip>
using namespace std;

// Global variables as defined and explained in the header file
Symbol *currentSym;          // ptr to current symbol
SymbolTable *SymTbl_Global;  // ptr to global symbol table
SymbolTable *SymTbl_Current; // ptr to currently active symbol table
QuadArray QuadList;          // list of Quads
int SymTbl_Count;            // count for naming nested symbol tables
string BlockName;            // name of block
string prevType;             // Used for storing the last encountered type

// Implementations of constructors and functions for the SymbolType class
SymbolType::SymbolType(string type_, SymbolType *arrType_, int width_) : type(type_), arrElementType(arrType_), width(width_) {}

// Implementations of constructors and functions for the symbol class
Symbol::Symbol(string name_, string type_, SymbolType *arrType_, int width) : name(name_), val("-"), offset(0), nestedTblPtr(NULL)
{
    sym_type = new SymbolType(type_, arrType_, width);
    size = sizeOfType(sym_type);
}

Symbol *Symbol::update_symbol(SymbolType *type_)
{
    // Update the type and size for the symbol
    sym_type = type_;
    size = sizeOfType(type_);
    return this;
}

// Implementations of constructors and functions for the symbolTable class
SymbolTable::SymbolTable(string name_) : name(name_), tempVarCount(0) {}

Symbol *SymbolTable::lookup(string name_)
{
    // Start searching for the symbol in the symbol table
    for (auto it = symTable.begin(); it != symTable.end(); it++)
    {
        if (it->name == name_)
        {
            return &(*it);
        }
    }

    // If not found, search for the variable in the parent symbol tables
    Symbol *s = NULL;
    if (this->parent != NULL)
    {
        s = this->parent->lookup(name_);
    }

    if (SymTbl_Current == this && s == NULL)
    {
        // If the symbol is still not found,
        // create the new symbol, add it to the symbol table and return a pointer to it
        Symbol *sym = new Symbol(name_);
        symTable.push_back(*sym);
        return &(symTable.back());
    }
    else if (s != NULL)
    {
        // If the symbol is found in one of the parent symbol tables, return it
        return s;
    }

    return NULL;
}

// function to generate a temporary variable for the current symbol table
Symbol *SymbolTable::gentemp(SymbolType *t, string initial_val)
{
    // Create the name for the temporary
    string name = "t" + to_string(SymTbl_Current->tempVarCount++);
    Symbol *sym = new Symbol(name);
    sym->sym_type = t;
    sym->val = initial_val; // Assign the initial value, if any
    sym->size = sizeOfType(t);

    // Add the temporary to the symbol table
    SymTbl_Current->symTable.push_back(*sym);
    return &(SymTbl_Current->symTable.back());
}

// function to print the symbol table in an appropriate format

void SymbolTable::print()
{
    for (int i = 0; i < 120; i++)
    {
        cout << '-';
    }
    cout << endl;
    cout << "SYMBOL TABLE : " << setfill(' ') << left << setw(20) << this->name<<endl;
    cout << "PARENT TABLE : " << setfill(' ') << left << setw(20) << ((this->parent != NULL) ? this->parent->name : "NULL") << endl;
    for (int i = 0; i < 120; i++)
    {
        cout << '-';
    }
    cout << endl;

    // Table Headers
    cout << setfill(' ') << left << setw(25) << "NAME";
    cout << left << setw(25) << "TYPE";
    cout << left << setw(25) << "INITIAL VALUE";
    cout << left << setw(15) << "SIZE";
    cout << left << setw(15) << "OFFSET";
    cout << left << "NESTED TABLE" << endl;

    for (int i = 0; i < 120; i++)
    {
        cout << '=';
    }
    cout << endl;

    list<SymbolTable *> tableList;

    // Print the symbols in the symbol table
    for (auto it = this->symTable.begin(); it != this->symTable.end(); it++)
    {
        cout << left << setw(25) << it->name;
        cout << left << setw(25) << check_type(it->sym_type);
        cout << left << setw(25) << (it->val != "" ? it->val : "-");
        cout << left << setw(15) << it->size;
        cout << left << setw(15) << it->offset;
        cout << left;

        if (it->nestedTblPtr != NULL)
        {
            cout << it->nestedTblPtr->name << endl;
            tableList.push_back(it->nestedTblPtr);
        }
        else
        {
            cout << "NULL" << endl;
        }
    }

    for (int i = 0; i < 120; i++)
    {
        cout << '=';
    }
    cout<<endl<<endl<<endl<<endl;

    // Recursively call the print function for the nested symbol tables
    for (auto it = tableList.begin(); it != tableList.end(); it++)
    {
        (*it)->print();
    }
}

// function to update the symbol table
void SymbolTable::update()
{
    list<SymbolTable *> tableList;
    int offset_;

    // Update the offsets of the symbols based on their sizes
    for (auto it = symTable.begin(); it != symTable.end(); it++)
    {
        if (it == symTable.begin())
        {
            it->offset = 0;
            offset_ = it->size;
        }
        else
        {
            it->offset = offset_;
            offset_ = it->offset + it->size;
        }

        if (it->nestedTblPtr != NULL)
        {
            tableList.push_back(it->nestedTblPtr);
        }
    }

    // Recursively call the update function to update the offsets of symbols of the nested symbol tables
    for (auto iter = tableList.begin(); iter != tableList.end(); iter++)
    {
        (*iter)->update();
    }
}

// Implementations of constructors and functions for the Quad class
Quad::Quad(string res, string arg1_, string operation, string arg2_) : result(res), arg1(arg1_), op(operation), arg2(arg2_) {}

Quad::Quad(string res, int arg1_, string operation, string arg2_) : result(res), op(operation), arg2(arg2_)
{
    arg1 = to_string(arg1_);
}

Quad::Quad(string res, float arg1_, string operation, string arg2_) : result(res), op(operation), arg2(arg2_)
{
    arg1 = to_string(arg1_);
}

void Quad::print_quad()
{
    if (op == "=") // Simple assignment
        cout << result << " = " << arg1;
    else if (op == "=[]")
        cout << result << " = " << arg1 << "[" << arg2 << "]";
    else if (op == "*=")
        cout << "*" << result << " = " << arg1;
    else if (op == "[]=")
        cout << result << "[" << arg1 << "]"
             << " = " << arg2;
    else if (op == "goto" || op == "param" || op == "return")
        cout << op << " " << result;
    else if (op == "call")
        cout << result << " = "
             << "call " << arg1 << ", " << arg2;
    else if (op == "label")
        cout << result << ": ";

    // Format to print unary operators
    else if (op == "= &" || op == "= *" || op == "= -" || op == "= ~" || op == "= !")
        cout << result << " " << op << arg1;

    // Format to print binary operators
    else if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "^" || op == "|" || op == "&" || op == "<<" || op == ">>")
        cout << result << " = " << arg1 << " " << op << " " << arg2;

    // Format to print relational operators
    else if (op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">=")
        cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;

    else
        cout << "Invalid operator";
}

// Implementations of constructors and functions for the quadArray class
void QuadArray::print()
{
    for (int i = 0; i < 30; i++)
    {
        cout << '*';
    }
    cout << endl;
    cout << "GENERATED THREE-ADDRESS CODE :-" << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << '*';
    }
    cout << endl;

    int count = 0;

    // Print each of the quads one by one
    for (auto it = this->quads.begin(); it != this->quads.end(); it++, count++)
    {
        if (it->op != "label")
        {
            cout << left << setw(4) << count << ":    ";
            it->print_quad();
        }
        else
        {
            cout << endl
                 << left << setw(4) << count << ": ";
            it->print_quad();
        }
        cout << endl;
    }
}

// Implementation of the makelist function
list<int> makelist(int i)
{
    list<int> l(1, i);
    return l;
}

// Implementation of the merge function
list<int> merge(list<int> &list1, list<int> &list2)
{
    list1.merge(list2);
    return list1;
}

// Implementation of the backpatch function
void backpatch(list<int> l, int address)
{
    for (auto it = l.begin(); it != l.end(); it++)
        QuadList.quads[*it].result = to_string(address);

}

// Overloaded emit functions
void emit(string op, string result, string arg1, string arg2)
{
    Quad *q = new Quad(result, arg1, op, arg2);
    QuadList.quads.push_back(*q);
}

void emit(string op, string result, int arg1, string arg2)
{
    Quad *q = new Quad(result, arg1, op, arg2);
    QuadList.quads.push_back(*q);
}

void emit(string op, string result, float arg1, string arg2)
{
    Quad *q = new Quad(result, arg1, op, arg2);
    QuadList.quads.push_back(*q);
}

// Implementation of the typecheck functions
bool typecheck(Symbol *&s1, Symbol *&s2)
{
    SymbolType *t1 = s1->sym_type;
    SymbolType *t2 = s2->sym_type;

    if (typecheck(t1, t2))
        return true;
    else if (s1 = convertType(s1, t2->type))
        return true;
    else if (s2 = convertType(s2, t1->type))
        return true;
    else
        return false;
}

bool typecheck(SymbolType *t1, SymbolType *t2)
{

    if (t1 == NULL && t2 == NULL)
        return true;
    else if (t1 == NULL || t2 == NULL)
        return false;
    else if (t1->type != t2->type)
        return false;

    return typecheck(t1->arrElementType, t2->arrElementType);
}

string check_type(SymbolType *type_)
{
    if (type_ == NULL)
        return "null";

    else if (type_->type == "void" || type_->type == "char" || type_->type == "int" || type_->type == "float" || type_->type == "block" || type_->type == "func")
        return type_->type;

    else if (type_->type == "ptr")
        return "ptr(" + check_type(type_->arrElementType) + ")";

    else if (type_->type == "arr")
        return "arr(" + to_string(type_->width) + ", " + check_type(type_->arrElementType) + ")";

    else
        return "unknown";
}


// Implementation of the convertIntToBool functionS
Expression *convertIntToBool(Expression *expr)
{

    if (expr->type != "bool")
    {
        expr->falselist = makelist(nextinstr()); // Add falselist for boolean expressions
        emit("==", expr->addr->name, "0");
        expr->truelist = makelist(nextinstr()); // Add truelist for boolean expressions
        emit("goto", "");
    }
    return expr;
}

// Implementation of the convertBoolToInt function
Expression *convertBoolToInt(Expression *expr)
{
    if (expr->type == "bool")
    {
        expr->addr = SymbolTable::gentemp(new SymbolType("int"));
        backpatch(expr->truelist, nextinstr());
        emit("=", expr->addr->name, "true");
        emit("goto", to_string(nextinstr() + 1));
        backpatch(expr->falselist, nextinstr());
        emit("=", expr->addr->name, "false");
    }
    return expr;
}

void switchTable(SymbolTable *newTable)
{
    SymTbl_Current = newTable;
}

int nextinstr()
{
    return QuadList.quads.size();
}

int sizeOfType(SymbolType *t)
{
    if (t->type == "void")
        return _SIZE_VOID;
    else if (t->type == "char")
        return _SIZE_CHAR;
    else if (t->type == "int")
        return _SIZE_INT;
    else if (t->type == "ptr")
        return _SIZE_POINTER;
    else if (t->type == "float")
        return _SIZE_FLOAT;
    else if (t->type == "arr")
        return t->width * sizeOfType(t->arrElementType);
    else if (t->type == "func")
        return _SIZE_FUNCTION;
    else
        return -1;
}

// Implementation of the convertType function
Symbol *convertType(Symbol *s, string t)
{
    Symbol *temp = SymbolTable::gentemp(new SymbolType(t));

    if (s->sym_type->type == "float")
    {
        if (t == "int")
        {
            emit("=", temp->name, "float2int(" + s->name + ")");
            return temp;
        }
        else if (t == "char")
        {
            emit("=", temp->name, "float2char(" + s->name + ")");
            return temp;
        }
        return s;
    }

    else if (s->sym_type->type == "int")
    {
        if (t == "float")
        {
            emit("=", temp->name, "int2float(" + s->name + ")");
            return temp;
        }
        else if (t == "char")
        {
            emit("=", temp->name, "int2char(" + s->name + ")");
            return temp;
        }
        return s;
    }

    else if (s->sym_type->type == "char")
    {
        if (t == "float")
        {
            emit("=", temp->name, "char2float(" + s->name + ")");
            return temp;
        }
        else if (t == "int")
        {
            emit("=", temp->name, "char2int(" + s->name + ")");
            return temp;
        }
        return s;
    }

    return s;
}

int main()
{
    SymTbl_Count = 0;                          // Initialize STCount to 0
    SymTbl_Global = new SymbolTable("Global"); // Create global symbol table
    SymTbl_Current = SymTbl_Global;            // Make global symbol table the currently active symbol table
    BlockName = "";

    yyparse();
    SymTbl_Global->update();
    QuadList.print(); // Print Three Address Code
    cout << endl << endl;

    for (int i = 0; i < 40; i++)
    {
        cout << '*';
    }
    cout << endl;
    cout << "GENERATED SYMBOL TABLES FOR EACH SCOPE:-" << endl;
    for (int i = 0; i < 40; i++)
    {
        cout << '*';
    }
    cout << endl << endl << endl;

    SymTbl_Global->print(); // Print symbol tables

    return 0;
}
