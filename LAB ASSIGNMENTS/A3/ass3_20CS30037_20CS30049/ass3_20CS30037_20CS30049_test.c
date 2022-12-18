/*  COMPILERS LAB: ASSIGNMENT 3  (Lexer for TinyC) 
    PRANAV NYATI (ROLL : 20CS30037) 
    SHREYAS JENA (ROLL : 20CS30049) 
*/

// TEST FILE 

#include<stdio.h>

static const double golden_ratio = 1.618033;
static const int num_months = 12;

enum Year {Jan = 1, Feb, March, April, May, June, July, Aug, Sept, Oct, Nov, Dec};

typedef struct{
    char* member1, member2;
    long int roll1, roll2;
}Compilers_grp;

extern char* yytext;
inline int cube(int s) {return s*s*s;}

void main(){


    // Testing for keywords

    _Bool flag = 1;
    double _Complex  complex_1 = 1.45 + 2.67i;

    unsigned long month_no = 12;

    enum Year _month;
    for (_month = Jan; _month <=Dec; _month++)     
        printf("%d ", _month);

    Compilers_grp our_group = {"Pranav", "Shreyas", 30037, 30049};
    Compilers_grp* our_ptr = &our_group;
    // Testing for identifiers and constants


    // integer constants
    int _a_1_A = 8765678;
    short int _b_1_B = 10;
    long long signed int _c_1_C = 12345654321;

    // float constants
    float F1_ = 37., F2_ = 49.E+5, F3_ = -37.49e-3, F4_ = .47E2, F5_ = 0.232e-3, F6_ = 34E-2;
    double _huge = 3.4e+307, _tiny = 1.7e-308, _d1 = .00;
    const double pi = 3.14159;

    // character constants
    char _1_c = '@', _2_c = '\?', _3_c = '\n', _4_c = '\v', _5_c = 'P';

    // string literals
    const char* str1 = "Even if we use // in a string literal, it is not treated as beginning of a single-line comment, as it is enclosed in double quotes\n";
    const char* str2 = " The same holds for a /* multi-line comment */ like this.";
    char s2[] = "" ;    /* Empty string check */

    // Testing for punctuators
    int arr[5] = {1, 2, 3, 4, 5};
    int temp = (arr[0]++) + (++arr[1]) + (arr[2]--) + (--arr[3]);
    printf("Team member 1: %s, Team member 2: %s\n", our_ptr->member1, our_group.member2);     // test for punctuators -> and .

    int num1 = 37, num2 = 49;
    while(flag){
        if ( (num1 < num2 && arr[1] == arr[3] && arr[2] != arr[4]) || (num1 >= arr[0]) )
            break;
        else
            continue;
    }
    
    temp += arr[0] - (arr[1] * arr[2]) / (arr[3] % arr[4]);

    num1 *= num2;
    num2 /= num1;
    temp %= arr[0];
    
    temp = (num1 > num2) ? num1 : num2;

    int bit1 = 1111, bit2 = 1010, bit3;
    bit1 &= bit2;
    bit3 = bit1 | bit2;
    bit1 ^= bit2;
    bit1 <<= 3;
    bit3 = bit1 ^ bit2;
    

    // Testing for comments

    /*
    Now if we have some text enclosed in double quotes inside a comment, it won't be treated as a string literal, so justice for both the cases.
    */
    

    // Ironically, a Test for a comment is itself a commment

    bit2 = bit3 >> 1;

    /* 
    Found this quote interesting in this context: "Code never lies, comments sometimes do."
    */
       
   return 0;
}