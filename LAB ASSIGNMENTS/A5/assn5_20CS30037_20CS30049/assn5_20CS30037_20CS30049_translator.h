/* 
 Compilers Lab : Assignment 5
 Group Members:
    1. Pranav Nyati (20CS30037)
    2. Shreyas Jena (20CS30049)
*/

// Header File for declaring Data Structures (Class Definitions) 
// & Global Function Prototypes

#ifndef __ASSN5_TRANSLATOR_H__
#define __ASSN5_TRANSLATOR_H__


#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// Declaration of size of basic data types

#define _SIZE_VOID      0        // void : 0 bytes
#define _SIZE_CHAR      1        // char : 1 byte
#define _SIZE_INT       4        // int  : 4 bytes
#define _SIZE_FLOAT     8        // float: 8 bytes
#define _SIZE_POINTER   4        // pointer: 4 bytes
#define _SIZE_FUNCTION  0        // function: 0 bytes


/* Class Declarations*/

class Symbol;        // An instance of Symbol class represents an element in the symbol table
class SymbolType;    // SymbolType class represents the type of a symbol
class SymbolTable;   // SymbolTable class represents the symbol table data structure

class Quad;          // An instance of Quad class represents a quadruple used in TAC generation
class QuadArray;     // represents the list of quads 

// class Expression;    // represents an expression used in the grammar as a non-terminal
// class Array;         // An instance of Array class represents an array type
// class Statement;    // represents a statement used in the grammar as a non-terminal

// Declaration of Global Variables

extern Symbol* currentSym;   // ptr to current symbol
extern SymbolTable* SymTbl_Global;   // ptr to global symbol table
extern SymbolTable* SymTbl_Current;    // ptr to currently active symbol table
extern QuadArray QuadList;  // list of Quads
extern int SymTbl_Count;    // count for naming nested symbol tables
extern string BlockName;    // variable for naming nested blocks in symbol table

extern  char* yytext;   // import the yytext variable (which stores the lexeme) from the lexer
extern  int yyparse();  // import the yyparse() function from bison parser


// ##################### Class definitions and member functions ##################

// class to represent symbol type
class SymbolType{
    public:
        string type;   // type of symbol (i.e, E.type)
        int width;     // width of symbol in bytes (i.e, E.width)
        SymbolType* arrElementType;   // type of array elements

        // constructor method
        SymbolType(string type_, SymbolType* arrElementType_ = NULL, int width_ = 1);

};

// class to represent symbol
class Symbol{
    public:
        string name;    // name of symbol
        SymbolType* sym_type;   // type of symbol
        string val; // value of symbol initially
        int size;   // size of symbol in bytes
        int offset; // offset of symbol in the symbol table
        SymbolTable *nestedTblPtr; // ptr to nested symbol table, to be used for functions and blocks

        // constructor method
        Symbol(string name_, string sym_type_ = "int", SymbolType* arrType_ = NULL, int width_ = 0);
        
        // method to update the attributes of a symbol
        Symbol* update_symbol(SymbolType* type_new);  // update changes made to symbol

};


// class to represent symbol table data structure
class SymbolTable{
public:
    string name;    // name of symbol
    int tempVarCount;   // count to keep track of the number of temporary variables in symbol table
    list<Symbol> symTable;  // list of all symbols in symbol table
    SymbolTable* parent;    // pointer to the parent symbol table of the current symbol table 

    // constructor
    SymbolTable(string name_ = "NULL");

    // method to lookup a symbol in symbol table using symbol's lexeme
    // returns a pointer to the symbol if found, else creates a new symbol and returns a pointer to it
    Symbol* lookup(string sym_name);  

    // static method to generate a new temporary variable, insert it in the symbol table and return a ptr to it 
    static Symbol* gentemp(SymbolType* type, string initial_val = "");   // method to generate a tenporary variable, store it in symbol table and return pointer to it

    void print();   // method to print contents of symbol table
    void update();  // update the offsets of existing entries in the symbol table
};

//class to represent a Quad
class Quad {
public:
    string op;  // operator of the TAC
    string arg1;    // 1st argument of the TAC
    string arg2;    // 2nd argument of the TAC(if any)
    string result;  // variable to store result of the TAC

    // overloaded constructors for Quad (for different types of arguments)
    Quad(string res, string arg1_, string operation = "=", string arg2_ = "");
    Quad(string res, int arg1_, string operation = "=", string arg2_ = "");
    Quad(string res, float arg1_, string operation = "=", string arg2_ = "");

    void print_quad();   // function to print quad
};


// class to represent array of quads
class QuadArray {
public:
    vector<Quad> quads;     // stores all generated quads in a vector
    
    void print();           // function to print all quads
};

// class to represent array type
class Array {
public:
    string arr_type;   // type of array
    Symbol* addr;      // base address of the array
    Symbol* array;     // pointer to the symbol table entry of the array
    SymbolType* type;  // type of the array, used for parsing of multi-dimensional arrays
};

// class to represent Statement, which is a non-terminal in the grammar
class Statement {
public:
    list<int> nextlist;     // statement's nextlist used for backpatching in control flow statements
};

//    Class to denote an Expression, which is a non-terminal in the grammar
class Expression {
public:
    string type;            // type of expression
    Symbol* addr;           // pointer to the symbol table entry of the expression
    list<int> truelist;     // expression's truelist used for backpatching for boolean expressions
    list<int> falselist;    // expression's falselist used for backpatching for boolean expressions
    list<int> nextlist;     // expression's nextlist used for backpatching in control flow statements
};


// ######################### Declaration of Helper Functions ######################

// function creates a new list containing an index i into the array of instructions
// and returns a pointer to the newly created list
list<int> makelist(int i);

// function merges two lists and returns a pointer to the merged list
list<int> merge(list<int> &list1, list<int> &list2);

// function to insert address as the target label for each of the instructions on the list l
void backpatch(list<int> l, int address);

//  An overloaded functon to add a new Quad of the form: result = arg1 op arg2 
//  overloaded for different types of arg1 (int, float or string)
void emit(string op, string result, string arg1 = "", string arg2 = "");
void emit(string op, string result, int arg1, string arg2 = "");
void emit(string op, string result, float arg1, string arg2 = "");


// function to check the compatibility of the types of symbols s1 and s2
// overloaded for symbol types t1 and t2
bool typecheck(Symbol* &s1, Symbol* &s2);
bool typecheck(SymbolType* t1, SymbolType* t2);

// function to print a type
string check_type(SymbolType* t);

//  function to convert an int to a bool
Expression* convertIntToBool(Expression* expr);

//  function to convert a bool to an int 
Expression* convertBoolToInt(Expression* expr);

// function to update the currently active symbol table to new_table
void switchTable(SymbolTable* new_table);

// function to return the count of the next instruction
int nextinstr();

// function to get the size of a type
int sizeOfType(SymbolType* t);

// Converts a symbol of one type to another and returns a pointer to the converted symbol
Symbol* convertType(Symbol* s, string t);


#endif
