// TEST FILE 1

// Testing of Declarations, Arithmetic Operations
// Declaration of variables (like int, float, char,etc.), 1-D arrays, 2-D arrays

int x = 37, y = 49;
float pi = 3.14;
char c1 = 'a', c2 = 'b';

int main () {

    int int_arr_1d[10];                          // 1D array declaration
    float float_arr_2d[20][50];                  // 2D array declaration

    // Variable Declaration
    int a1, a2, a3, a4, a5, a6, a7;
    int i = -55;
    int j, k;
    char ch = 'c', d = 'd';                     // character definitions

    int *ptr, ***ptr1;                          // pointer declarations
    float *ptr2, **ptr3;                  

    // Arithmetic Operations
    a1 = x + y;
    x++;
    a2 = x - y;
    a3 = x * (--y);
    a4 = x / y;
    a5 = x % y;
    a6 = x & y;
    a7 = x | y;
    a2 *= x;
    a3 /= y;
    a4 %= ++a1;
    a5 &= a1;
    a6 |= a1;
    a7 ^= a1;

    j = i << 3;
    k = i >> 2;

    return 0;
}