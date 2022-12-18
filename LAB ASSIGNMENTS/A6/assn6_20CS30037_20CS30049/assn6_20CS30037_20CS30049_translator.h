/* 
 Compilers Lab : Assignment 6
 Group Members:
    1. Pranav Nyati (20CS30037)
    2. Shreyas Jena (20CS30049)
*/

// Header File for declaring Data Structures (Class Definitions) 
// & Global Function Prototypes

#ifndef __ASSN6_TRANSLATOR_H
#define __ASSN6_TRANSLATOR_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

// Declaration of size of basic data types

#define _SIZE_VOID      0        // void : 0 bytes
#define _SIZE_CHAR      1        // char : 1 byte
#define _SIZE_INT       4        // int  : 4 bytes
#define _SIZE_FLOAT     8        // float: 8 bytes
#define _SIZE_POINTER   4        // pointer: 4 bytes
#define _SIZE_FUNCTION  0        // function: 0 bytes

/* Class Declarations*/

class Symbol;                           // An instance of Symbol class represents an element in the symbol table
class SymbolType;                       // SymbolType class represents the type of a symbol
class SymbolValue;                      // SymbolValue class represents the value stored by a symbol in the symbol table
class SymbolTable;                      // SymbolTable class represents the symbol table data structure

class Quad;                             // An instance of Quad class represents a quadruple used in TAC generation
class QuadArray;                        // represents the list of quads 

/* External Variable Declarations*/

extern QuadArray QuadList;              // stores the list of quads
extern SymbolTable SymTbl_Global;       // stores the global symbol table object
extern SymbolTable* SymTbl;             // pointer to the current symbol table

extern char* yytext;                    // import the yytext variable (which stores the lexeme) from the lexer
extern int yyparse();                   // import the yyparse() function from bison parser

// Defining all opcodes
typedef enum  {

    ADD, SUB, MULT, DIV, MOD, SL, SR, 
    BW_AND, BW_OR, BW_XOR, 
    BW_U_NOT ,U_PLUS, U_MINUS, REFERENCE, DEREFERENCE, U_NEG, 
    GOTO_EQ, GOTO_NEQ, GOTO_GT, GOTO_GTE, GOTO_LT, GOTO_LTE, IF_GOTO, IF_FALSE_GOTO, 
    CtoI, ItoC, FtoI, ItoF, FtoC ,CtoF, 
    ASSIGN, GOTO, RETURN, PARAM, CALL, ARR_IDX_ARG, ARR_IDX_RES, FUNC_BEG, FUNC_END, L_DEREF

}opcode;

// Defining all supported data types
typedef enum {

    INT,    
    FLOAT,
    CHAR,
    VOID,
    BOOL,
    POINTER,
    ARRAY,
    FUNCTION

}data_type;

// ##################### Class definitions and member functions ##################

// class to represent symbol type
class SymbolType {

    public:

        int num_ptrs;                   // useful for pointer types
        data_type type;                  // type of symbol (i.e, E.type)
        data_type base_type;              // In case of arrays, points to base type; in case of num_ptrs, points to the type of value pointed
        vector<int> dims;               // In case of array type, this is used to store array dimensions

};

// class to represent symbol value
class SymbolValue {

    public:
    
        int int_;           // stores int value
        char char_;         // stores char value
        float flt_;         // stores float value
        void* ptr_;         // stores ptr value

        // functions to initialize symbol with given value type
        void init(int val);
        void init(char val);
        void init(float val);

};

// class to represent an element in the symbol table
class Symbol {

    public:

        // member variables
        string name;                // symbol name
        SymbolType type;            // symbol data type
        SymbolValue* init_val;      // initial value
        int size;                   // size of symbol
        int offset;                 // offset of symbol 
        SymbolTable* nested_table;  // ptr to nested table (only for functions and other block scopes)

        // Constructor
        Symbol();

};

// class to represent a symbol table
class SymbolTable {

    public:

        // member variables
        map<string, Symbol*> table;                 // hashtable to map string symbol names to corresponding entries in symbol table
        vector<Symbol*> symbols;                    // list of symbols in symbol table
        int offset;                                 // variable to maintain offset
        static int temp_count;                      // maintains count of temp variables

        // constructor and member functions
        SymbolTable();

        Symbol* lookup(string name, data_type t = INT, int pc = 0);
        string gentemp(data_type t = INT);
        Symbol* find_glbl(string name);
        void print_table(string tableName);

};

// function to represent a TAC quad
class Quad {

    public:

        // member variables
        opcode op;              // operator of the TAC
        string arg1;            // 1st argument of the TAC
        string arg2;            // 2nd argument of the TAC(if any)
        string result;          // variable to store result of the TAC

        // constructor and member functions
        Quad(string, string, string, opcode);

        // function to print quad
        string print_quad();

};

// class to represent array of quads
class QuadArray {

    public:

        // member variables
        vector<Quad> quads;     // stores all generated quads in a vector

        // member functions
        void print_quads();     // function to print all quads

};

// class to represent a parameter
class Parameter {

    public:

        // member variables
        string name;            // parameter name
        SymbolType type;        // parameter type

};

class Expression {

    public:

        // member variables
        int instr;                  // instruction number of the expression
        data_type type;             // Type of the expression
        string addr;                // The symbol table entry 
        list<int> truelist;         // Truelist for boolean expressions
        list<int> falselist;        // Falselist for boolean expressions
        list<int> nextlist;         // Nextlist for statement expressions
        int dim;                    // Used to represent array dimensions
        string* name;               // Symbol name for array expression

        // constructor
        Expression();

};

// class to represent a declaration
class Declaration {

    public:

        // member variables
        string name;                // Name of the declaration
        int num_ptrs;               // Number of num_ptrs
        data_type type;             // type of declaration
        data_type nextType;         // defines base type (for arrays or pointers)
        vector<int> li;             // List of instructions for the declaration
        Expression* init_val;       // Initial value of the declaration
        int pc;                     // Useful for num_ptrs and arrays

};


//  An overloaded functon to add a new Quad of the form: result = arg1 op arg2 
//  overloaded for different types of arg1 (int, float or string)
void emit(string result, string arg1, string arg2, opcode op);
void emit(string result, int constant, opcode op);
void emit(string result, char constant, opcode op);
void emit(string result, float constant, opcode op);


// function creates a new list containing an index i into the array of instructions
// and returns a pointer to the newly created list
list<int> makelist(int i);

// function merges two lists and returns a pointer to the merged list
list<int> merge(list<int> list1, list<int> list2);

// function to insert address as the target label for each of the instructions on the list l
void backpatch(list<int> l, int address);

// Converts a symbol of one type to another and returns a pointer to the converted symbol
void convertToType(Expression* arg, Expression* res, data_type toType);

void convertToType(string t, data_type to, string f, data_type from);

//  function to convert an int to a bool
void convertIntToBool(Expression* expr);

// Auxiliary function to get the size of a type
int sizeOfType(data_type t);

// Auxiliary function to print a type
string checkType(SymbolType t);

// Auxiliary function to get the initial value of a symbol
string getInitVal(Symbol* sym);

#endif