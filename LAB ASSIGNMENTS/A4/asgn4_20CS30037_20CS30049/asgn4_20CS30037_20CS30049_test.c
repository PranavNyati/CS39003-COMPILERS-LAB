/*  COMPILERS LAB: ASSIGNMENT 4  
    PRANAV NYATI (ROLL : 20CS30037) 
    SHREYAS JENA (ROLL : 20CS30049) 
*/

// TEST FILE 

static const double golden_ratio = 1.618033;
static const int num_months = 12;

enum Year {Jan = 1, Feb, March, April, May, June, July, Aug, Sept, Oct, Nov, Dec};

extern char* yytext;

int *restrict temp;
volatile int a;
auto float b;

inline int cube(int s) {return s*s*s;}

void main(){

    // Testing for keywords

    _Bool flag = 1;
    double _Complex  complex_1;

    register char c;

    unsigned long month_no = 12;

    enum Year _month;
    for (_month = Jan; _month <=Dec; _month++)     
        printf("%d ", _month);

    // Testing for identifiers and constants

    // integer constants
    int _a_1_A = 8765678;
    short signed int _b_1_B = -50;
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
    bit2 = bit3 >> 1;

    // Testing for control flow constructs

    int mat1[3][5];

    // Testing nested for loop 
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            mat1[i][j] = 5*i + j;
        }
    }

    // Testing for while loop
    int i = 20;
    while(i >= 0){
        printf("%d ", i);
        i -= 2;
    }
    printf("\n");

    // Testing for do-while loop and if-else statements by implementing Collatz conjecture
    int n = 37;

    printf("%d ", n);
    do {
        if (n%2 == 0)
            n /= 2;
        else
            n = 3*n + 1;

        printf("%d ", n);
    } while (n > 1);
    printf("\n");

    // Testing for switch-case statements
    int day = 6;
    switch (day) {
        case 1:
            printf("Sad, its Monday again.\n");
            break;
        case 2:
            printf("Tuesday, 8:00 AM classes, nooo!\n");
            break;
        case 3:
            printf("Wednesday, this too shall pass.\n");
            break;
        case 4:
            printf("Thursday, almost there.\n");
            break;
        case 5:
            printf("Friday, TGIF!\n");
            break;
        case 6:
            printf("Saturday, yay, weekend!\n");
            break;
        case 7:
            printf("Sunday, time to sleep.\n");
            break;  
        default:
            printf("Invalid day number");
            break;
    }

    // Testing for comments

    /*
    Now if we have some text enclosed in double quotes inside a comment, it won't be treated as a string literal, so justice for both the cases.
    */
    

    // Ironically, a Test for a comment is itself a commment
    
    /* 
    Found this quote interesting in this context: "Code never lies, comments sometimes do."
    */
       
   return 0;
}