/*
    Compilers Lab Assignment - 6
    Group Members :-
        Pranav Nyati - 20CS30037
        Shreyas Jena - 20CS30049
*/

// cxx file defining functionalities for generation of TAC
#include "assn6_20CS30037_20CS30049_translator.h"
#include <iomanip>
using namespace std;

// define global variables
QuadArray QuadList;                 // list of quads
SymbolTable SymTbl_Global;          // global symbol table object
SymbolTable* SymTbl;                // pointer to symbol table

// Initialize global and static variables
int nextinstr = 0;
int SymbolTable::temp_count = 0;

// Implementations of constructors and functions for the SymbolValue class
void SymbolValue::init(int val) 
{
    char_ = val;
    flt_ = val;
    int_ = val;
    ptr_ = NULL;
}

void SymbolValue::init(char val) 
{
    char_ = val;
    flt_ = val;
    int_ = val;    
    ptr_ = NULL;
}

void SymbolValue::init(float val) 
{
    char_ = val;
    flt_ = val;
    int_ = val;    
    ptr_ = NULL;
}


// Implementations of constructors and functions for the symbol class
Symbol::Symbol(): nested_table(NULL) {}

// Implementations of constructors and functions for the SymbolTable class
SymbolTable::SymbolTable(): offset(0) {}

// function to look up a symbol in the symbol table
Symbol* SymbolTable::lookup(string name, data_type t, int pc) 
{
    if (table.count(name) == 0)         // if symbol is not present, create a new entry anf add to symbol table
    {
        // create a new symbol and initialize attributes
        Symbol* sym = new Symbol();
        sym->name = name;
        sym->type.type = t;
        sym->offset = offset;
        sym->init_val = NULL;

        if (pc == 0) 
        {
            sym->size = sizeOfType(t);
            offset += sym->size;
        }

        else 
        {
            sym->size = _SIZE_POINTER;
            sym->type.base_type = t;
            sym->type.num_ptrs = pc;
            sym->type.type = ARRAY;
        }

        symbols.push_back(sym);
        table[name] = sym;
    }

    return table[name];
}

// function to find occurrence of symbol in the global symbol table
Symbol* SymbolTable::find_glbl(string name) 
{
    return (table.count(name) ? table[name] : NULL);
}

// function to generate a temporary variable and add to symbol table
string SymbolTable::gentemp(data_type t) 
{
    // Create the name for the temporary
    string temp_name = "t" + to_string(SymbolTable::temp_count);
    SymbolTable::temp_count++;
    
    // Create a new symbol and initialize the required attributes
    Symbol* sym = new Symbol();
    sym->name = temp_name;
    sym->size = sizeOfType(t);
    sym->offset = offset;
    sym->type.type = t;
    sym->init_val = NULL;

    offset += sym->size;    // update offset
    symbols.push_back(sym); // add symbol to list of symbols in symbol table
    table[temp_name] = sym;  // Add the temporary to the symbol table

    return temp_name;
}

// function to print symbol table
void SymbolTable::print_table(string table_name) 
{

    for (int i = 0; i < 120; i++) 
    {
        cout << '=';
    }

    cout << endl;

    // Symbol table heading
    cout << "SYMBOL TABLE: " << setfill(' ') << left << setw(50) << table_name << endl;

    for (int i = 0; i < 120; i++)
    {
        cout << '=';
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

    // For storing nested symbol tables
    vector<pair<string, SymbolTable*>> table_list;

    // Print the symbols in the symbol table
    for (int i = 0; i < (int)symbols.size(); i++) 
    {

        Symbol* sym = symbols[i];

        // print symbol attributes in formatted manner
        cout << left << setw(25) << sym->name;
        cout << left << setw(25) << checkType(sym->type);
        cout << left << setw(20) << getInitVal(sym);
        cout << left << setw(15) << sym->size;
        cout << left << setw(15) << sym->offset;
        cout << left;

        // if symbol is actually a function name
        if (sym->nested_table != NULL) 
        {
            string nested_table_name = table_name + "." + sym->name;        
            cout << nested_table_name << endl;
            table_list.push_back({nested_table_name, sym->nested_table});       // add nested table to table list
        }

        else
            cout << "NULL" << endl;

    }

    for (int i = 0; i < 120; i++)
    {
        cout << '=';
    }

    cout << endl << endl;

    // Recursively call the print function for the nested symbol tables
    for (auto it = table_list.begin(); it != table_list.end(); it++) 
    {
        pair<string, SymbolTable*> p = (*it);
        p.second->print_table(p.first);
    }

}


// Implementations of constructors and functions for the Quad class
Quad::Quad(string res_, string arg1_, string arg2_, opcode op_): op(op_), arg1(arg1_), arg2(arg2_), result(res_) {}

// function to print quad
string Quad::print_quad() 
{

    string out = "";

    if (op >= ADD && op <= BW_XOR) 
    {                 // Binary operators
        out += (result + " = " + arg1 + " ");

        switch(op) 
        {
            case ADD: out += "+"; break;
            case SUB: out += "-"; break;
            case MULT: out += "*"; break;
            case DIV: out += "/"; break;
            case MOD: out += "%"; break;
            case SL: out += "<<"; break;
            case SR: out += ">>"; break;
            case BW_AND: out += "&"; break;
            case BW_OR: out += "|"; break;
            case BW_XOR: out += "^"; break;
        }

        out += (" " + arg2);
    }

    else if (op >= BW_U_NOT && op <= U_NEG) 
    {        // Unary operators
        out += (result + " = ");

        switch(op) 
        {
            case BW_U_NOT: out += "~"; break;
            case U_PLUS: out += "+"; break;
            case U_MINUS: out += "-"; break;
            case REFERENCE: out += "&"; break;
            case DEREFERENCE: out += "*"; break;
            case U_NEG: out += "!"; break;
        }

        out += arg1;
    }

    else if (op >= GOTO_EQ && op <= IF_FALSE_GOTO) 
    { // Conditional operators
        out += ("if " + arg1 + " ");

        switch(op) 
        {
            case GOTO_EQ: out += "=="; break;
            case GOTO_NEQ: out += "!="; break;
            case GOTO_GT: out += ">"; break;
            case GOTO_GTE: out += ">="; break;
            case GOTO_LT: out += "<"; break;
            case GOTO_LTE: out += "<="; break;
            case IF_GOTO: out += "!= 0"; break;
            case IF_FALSE_GOTO: out += "== 0"; break;
        }

        out += (" " + arg2 + " goto " + result);
    }

    else if (op >= CtoI && op <= CtoF) 
    {             // Type Conversion functions
        out += (result + " = ");

        switch(op) 
        {
            case CtoI: out += "CharToInt"; break;
            case ItoC: out += "IntToChar"; break;
            case FtoI: out += "FloatToInt"; break;
            case ItoF: out += "IntToFloat"; break;
            case FtoC: out += "FloatToChar"; break;
            case CtoF: out += "CharToFloat"; break;
        }

        out += ("(" + arg1 + ")");
    }

    else if (op == ASSIGN)                     // Assignment operator
        out += (result + " = " + arg1);

    else if (op == GOTO)                         // Goto
        out += ("goto " + result);

    else if (op == RETURN)                       // Return from a function
        out += ("return " + result);

    else if (op == PARAM)                        // Parameters for a function
        out += ("param " + result);

    else if (op == CALL)                         // Call a function
    {
        if (arg2.size() > 0)
            out += (arg2 + " = ");
        out += ("call " + result + ", " + arg1);
    }

    else if (op == ARR_IDX_ARG)                  // Array indexing
        out += (result + " = " + arg1 + "[" + arg2 + "]");

    else if (op == ARR_IDX_RES)                  // Array indexing
        out += (result + "[" + arg2 + "] = " + arg1);

    else if (op == FUNC_BEG)                     // Function begin
        out += (result + ": ");

    else if (op == FUNC_END) {                   // Function end
        out += ("function " + result + " ends");
    }

    else if (op == L_DEREF)                      // Dereference
        out += ("*" + result + " = " + arg1);

    return out;
}

// function to print list of TAC quads
void QuadArray::print_quads() {

    for (int i = 0; i < 120; i++)
        cout << '-';

    cout << endl;
    cout << "THREE ADDRESS CODE (TAC):" << endl;

    for (int i = 0; i < 120; i++)
        cout << '-';

    cout << endl;

    // Print each of the quads one by one
    for (int i = 0; i < (int)quads.size(); i++) 
    {
        if (quads[i].op != FUNC_BEG && quads[i].op != FUNC_END)
            cout << left << setw(4) << i << ":    ";

        else if (quads[i].op == FUNC_BEG)
            cout << endl << left << setw(4) << i << ": ";

        else if (quads[i].op == FUNC_END)
            cout << left << setw(4) << i << ": ";

        cout << quads[i].print_quad() << endl;
    }
    cout << endl;
}


// Implementations of constructors for the expression class
Expression::Expression(): dim(0), name(NULL) {}

// Overloaded emit functions
void emit(string result, string arg1, string arg2, opcode op) 
{
    Quad q(result, arg1, arg2, op);
    QuadList.quads.push_back(q);
    nextinstr++;
}

void emit(string result, int constant, opcode op) 
{
    Quad q(result, to_string(constant), "", op);
    QuadList.quads.push_back(q);
    nextinstr++;
}

void emit(string result, char constant, opcode op) 
{
    Quad q(result, to_string(constant), "", op);
    QuadList.quads.push_back(q);
    nextinstr++;
}

void emit(string result, float constant, opcode op) 
{
    Quad q(result, to_string(constant), "", op);
    QuadList.quads.push_back(q);
    nextinstr++;
}


// Implementation of the makelist function
list<int> makelist(int i) 
{
    list<int> l(1, i);
    return l;
}

// Implementation of the merge function
list<int> merge(list<int> list1, list<int> list2) 
{
    list1.merge(list2);
    return list1;
}

// Implementation of the backpatch function
void backpatch(list<int> l, int address) 
{
    string str = to_string(address);

    for (list<int>::iterator it = l.begin(); it != l.end(); it++) 
    {
        QuadList.quads[*it].result = str;
    }
}


// Implementation of the overloaded convertToType functions
void convertToType(Expression* arg, Expression* res, data_type toType) 
{
    
    if (res->type == toType)
        return;

    if (res->type == FLOAT) 
    {
        if (toType == INT)
            emit(arg->addr, res->addr, "", FtoI);

        else if (toType == CHAR)
            emit(arg->addr, res->addr, "", FtoC);
    }

    else if (res->type == INT) {
        if (toType == FLOAT)
            emit(arg->addr, res->addr, "", ItoF);

        else if (toType == CHAR)
            emit(arg->addr, res->addr, "", ItoC);
    }

    else if (res->type == CHAR) {
        if (toType == FLOAT)
            emit(arg->addr, res->addr, "", CtoF);

        else if (toType == INT)
            emit(arg->addr, res->addr, "", CtoI);
    }
}

// function to convert from one type to another
void convertToType(string t, data_type to, string f, data_type from) 
{
    if (to == from)
        return;
    
    if (from == FLOAT) 
    {
        if (to == INT)
            emit(t, f, "", FtoI);

        else if (to == CHAR)
            emit(t, f, "", FtoC);
    }

    else if (from == INT) 
    {
        if (to == FLOAT)
            emit(t, f, "", ItoF);

        else if (to == CHAR)
            emit(t, f, "", ItoC);
    }

    else if (from == CHAR) 
    {
        if (to == FLOAT)
            emit(t, f, "", CtoF);

        else if (to == INT)
            emit(t, f, "", CtoI);
    }
}

// Implementation of the convertIntToBool function
void convertIntToBool(Expression* expr) 
{
    if (expr->type != BOOL) 
    {
        expr->type = BOOL;
        expr->falselist = makelist(nextinstr);    // Add falselist for boolean expressions
        emit("", expr->addr, "", IF_FALSE_GOTO);
        expr->truelist = makelist(nextinstr);     // Add truelist for boolean expressions
        emit("", "", "", GOTO);
    }
}

// Implementation of the sizeOfType function
int sizeOfType(data_type t) 
{
    if (t == VOID)
        return _SIZE_VOID;

    else if (t == CHAR)
        return _SIZE_CHAR;

    else if (t == INT)
        return _SIZE_INT;

    else if (t == POINTER)
        return _SIZE_POINTER;

    else if (t == FLOAT)
        return _SIZE_FLOAT;

    else if (t == FUNCTION)
        return _SIZE_FUNCTION;

    else
        return 0;
}

// Implementation of the checkType function
string checkType(SymbolType t) 
{
    if (t.type == VOID)
        return "void";

    else if (t.type == CHAR)
        return "char";

    else if (t.type == INT)
        return "int";

    else if (t.type == FLOAT)
        return "float";

    else if (t.type == FUNCTION)
        return "function";

    else if (t.type == POINTER) 
    {        // Depending on type of pointer
        string tp = "";
        if (t.base_type == CHAR)
            tp += "char";

        else if (t.base_type == INT)
            tp += "int";

        else if (t.base_type == FLOAT)
            tp += "float";

        tp += string(t.num_ptrs, '*');
        return tp;
    }

    else if (t.type == ARRAY)               // Depending on type of array
    {          
        string tp = "";
        if (t.base_type == CHAR)
            tp += "char";

        else if (t.base_type == INT)
            tp += "int";

        else if (t.base_type == FLOAT)
            tp += "float";

        vector<int> dim = t.dims;

        for (int i = 0; i < (int)dim.size(); i++) 
        {
            if (dim[i])
                tp += "[" + to_string(dim[i]) + "]";
            else
                tp += "[]";
        }

        if ((int)dim.size() == 0)
            tp += "[]";

        return tp;
    }

    else
        return "unknown";
}

// Implementation of the getInitVal function
string getInitVal(Symbol* sym) 
{
    if (sym->init_val != NULL) 
    {
        if (sym->type.type == INT)
            return to_string(sym->init_val->int_);

        else if (sym->type.type == CHAR)
            return to_string(sym->init_val->char_);

        else if (sym->type.type == FLOAT)
            return to_string(sym->init_val->flt_);

        else
            return "-";
    }
    else
        return "-";
}
