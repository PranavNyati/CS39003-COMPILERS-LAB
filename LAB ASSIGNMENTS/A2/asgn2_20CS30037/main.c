// COMPILERS LAB
// Name: Pranav Nyati
// Roll: 20CS30037
// Assignment 2

# include "myl.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int main(){

    char *newline = "\n";
    // Test 1: Testing printStr function
    printStr("TEST 1: TESTING printStr FUNCTION\n");
    printStr(newline);
    char *test_1[6] = {"The printStr function prints a string to stdout using syscall functionality.", 
                       "It doesn't use the standard i/o library printf call for printing a string.", 
                       "The next string that will be printed is a null string.",
                       "",
                       "The next string that will be printed is a single space character.",
                       " "};
    
    for(int i=0; i < 6; i++){
        printStr("\""); 
        int ret = printStr(test_1[i]);   // ret is the return value of the printStr (the num of chars printed)
        printStr("\" -> Number of characters printed = ");
        printInt(ret);
        printStr(newline);
    }
    printStr(newline);
    printStr(newline);

    // Test2: Testing the printInt function
    printStr("TEST 2: TESTING printInt FUNCTION\n");
    printStr(newline);
    int test_2[8] = {0, 17, -56, 7265,  97531, -100000, INT_MAX, INT_MIN};
    for(int i=0; i<8; i++){
        int ret = printInt(test_2[i]);
        printStr(" -> number of characters printed = ");
        printInt(ret);
        printStr(newline);
    }
    printStr(newline);
    printStr(newline);

    // Test3: Testing the printFlt function
    printStr("TEST 3: TESTING printFlt FUNCTION\n");
    printStr(newline);
    float test_3[8] = {0.F, -723.01049F, -3.141592653F, 30037.F, 16.149F, 4.000079F, -0.00106F, 0.001};
    for(int i=0; i<8; i++){
        int ret = printFlt(test_3[i]);
        printStr(" -> number of characters printed = ");
        printInt(ret);
        printStr(newline);
    }
    printStr(newline);
    printStr(newline);

    // Test4: Testing readInt function
    printStr("TEST 4: TESTING readInt FUNCTION\n");
    printStr(newline);
    int test_4;
    int rep = 1;
    while(rep == 1){
        printStr("Enter an integer: ");
        int ret = readInt(&test_4);
        if(ret == ERR) 
            printStr("Invalid input. ");
        else{
            printStr("Successfuly read integer => ");
            printInt(test_4);
        }
        printStr("\nTo continue reading an integer, enter 1 otherwise 0: ");
        readInt(&rep);

        if (rep == 0)
            break;
    }
    printStr(newline);
    printStr(newline);

    // Test5: Testing readFlt function
    printStr("TEST 5: TESTING readFlt FUNCTION\n");
    printStr(newline);
    float test_5;
    rep = 1;
    while(rep == 1){
        printStr("Enter a float: ");
        int ret = readFlt(&test_5);
        if(ret == ERR) 
            printStr("Invalid input. ");
        else{
            printStr("Successfuly read float: ");
            printFlt(test_5);
        }
        printStr("\nTo continue reading enter 1 otherwise 0: ");
        readInt(&rep);
        
        if(rep == 0)
            break;
    } 
    printStr(newline);
    printStr("Testing Complete!\n");

    return 0;
}