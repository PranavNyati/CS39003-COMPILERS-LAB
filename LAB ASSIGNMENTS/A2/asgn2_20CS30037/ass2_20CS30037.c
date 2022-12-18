// COMPILERS LAB
// Name: Pranav Nyati
// Roll: 20CS30037
// Assignment 2

#include "myl.h"

# define BUFSIZE 100
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define PRECISION 6


// function to print a string using syscall
int printStr(char *str){
    int len = 0;

    while(str[len] != '\0')
        len++;

    __asm__ __volatile__(
        "movl $1, %%eax \n\t"        // eax <-- 1; for system call (to invoke the write system call)
		"movq $1, %%rdi \n\t"        // rdi <-- 1; (1st arg to write system call -> file descriptor; fd = 1 denotes stdout) 
		"syscall \n\t"   
		:
		:"S"(str), "d"(len)          // S refers to char array from which string is to be printed; d refers to string length
    );

    return len;
}

// function to read an integer from stdin using syscall
int readInt(int *n){
    char input[BUFSIZE];
    int len;

    __asm__ __volatile__ (
        "movl $0, %%eax \n\t"        // eax <-- 0; for system call (to invoke the read system call)
        "movq $0, %%rdi \n\t"        // rdi <-- 0; (1st arg to read system call -> file descriptor; fd = 0 denotes stdin)
        "syscall \n\t"            
        : "=a"(len)                  // a refers to return value of system call for read (returns no of bytes read)
        :"S"(input), "d"(BUFSIZE)    // S refers to char array in which input is to be stored; d refers to buffer size
    );  

    long int_val = 0;
    int sign_flag = 1, idx = 0;

    if (len <= 0){                     // if there is an error in reading from stdin, the syscall returns -1 indicating error
        // int_val = INT_MIN;
        return ERR;                   // if the user enters an empty line (i.e. just hits enter), the syscall returns 0 indicating end of input; so no integer is read
    }

    if (input[idx] == '-') {
        sign_flag = -1;
        idx++;
    } 

    else if (input[idx] == '+') {        // in case a user enters a '+' sign to indicate a positive int, we skip the '+' sign
        idx++;
    }

    if (input[idx] == '\n') {            // if the user enters the sign and just after hits enter, no input is read, so we return ERR 
        return ERR;                       
    }

    // evaluating the absolute value of the entered integer from the input sequence of digits
    while (idx < len && input[idx] != '\n') {
        if (input[idx] < '0' || input[idx] > '9') {        
            return ERR;
        }
        int curr_digit = (int)(input[idx] - '0');
        int_val *= 10;
        int_val += curr_digit;
        idx++;
    }

    int_val *= sign_flag;

    if(int_val > INT_MAX || int_val < INT_MIN)     // if entered integer is out of bounds for a 32-bit integer, return ERR
        return ERR;

    *n = (int)int_val;

    return OK;
}


// function to print an integer to stdout using syscall
int printInt(int n){

    char output[BUFSIZE];
    int num_char = 0;
    long int_val = n;

    if (int_val == 0) {           // if the integer argument is 0
        output[num_char++] = '0';
    }

    if (int_val < 0) {
        output[num_char++] = '-';
        int_val *= -1;
    }

    // evaluating the sequence of digits in the integer and storing in the output buffer
    while (int_val > 0) {
        output[num_char++] = (int_val % 10) + '0';
        int_val /= 10;
        if (num_char >= BUFSIZE) {  // if the integer to be printed is too large to fit in the buffer, we return ERR
            return ERR;
        } 
    }

    int j = (output[0] == '-') ? 1 : 0;
    int k = num_char - 1;

    while(j < k){
        char temp = output[j];
        output[j++] = output[k];
        output[k--] = temp;
    }

    output[num_char] = '\0';    

    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(output), "d"(num_char)
    );
    
    return num_char;
}

// function to read a floating point value from the stdin using syscall
int readFlt(float *f ){

    char input[BUFSIZE];
    int len;

    __asm__ __volatile__ (
        "movl $0, %%eax \n\t"        // eax <-- 0; for system call (to invoke the read system call)
        "movq $0, %%rdi \n\t"        // rdi <-- 0; (1st arg to read system call -> file descriptor; fd = 0 denotes stdin)
        "syscall \n\t"            
        : "=a"(len)                  // a refers to return value of system call for read
        :"S"(input), "d"(BUFSIZE)    // S refers to char array in which input is to be stored; d refers to buffer size
    );  

    int sign_flag = 1, idx = 0, exp_sign = 1, exp = 0, exp_flag = 0; 
    float float_val = 0;

    if (len <= 0)
        return ERR;
    
    if (input[idx] == '-') {
        sign_flag = -1;
        idx++;
    } 
    else if (input[idx] == '+') {        // in case a user enters a '+' sign to indicate a positive float value, we skip the '+' sign
        idx++;
    }

    if (input[idx] == '\n') {            // if the user enters the sign and just after hits enter, no input is read, so we return ERR
        return ERR;                 
    }
    
    // parsing the float value before decimal point or the exponent
    while ((idx < len) && (input[idx] != '\n') && (input[idx] != '.') && (input[idx] != 'E') && (input[idx] != 'e')){
        if (input[idx] < '0' || input[idx] > '9') {       
            return ERR;
        }
        float_val *= 10;
        float_val += (int)(input[idx] - '0');
        idx++; 
    }

    // parsing the float value after decimal point
    if (idx < len && input[idx] == '.') {
        
        idx++;
        float dec = 010.F;

        if (input[idx] == '\n') {            // if the user enters the decimal point and just after hits enter, then the float value is the part read before decimal
                float_val *= sign_flag;
                *f = (float)float_val;
                return OK; 
        }
 
        // evaluating the value after decimal point but before the exponent
        while((idx < len) && (input[idx] != '\n') && (input[idx] != 'E') && (input[idx] != 'e')){
            if (input[idx] < '0' || input[idx] > '9') {       
                return ERR;
            }
            float curr_float = (float)(input[idx] - '0');
            float_val += (curr_float/dec);
            dec *= 10;
            idx++;
        }
    }

    // parsing the float value after 'E' or 'e'   
    if (idx < len && (input[idx] == 'E' || input[idx] == 'e')) {
        exp_flag = 1;
        idx++;

        if (input[idx] == '+') {        // in case a user enters a '+' sign to indicate a positive exponent, we skip the '+' sign
            idx++;
        }
        else if (input[idx] == '-') {
            exp_sign = -1;
            idx++;
        } 

        if(input[idx] == '\n') {        // if the user enters the 'E' or 'e' and just after hits enter, then it is an invalid float value
            return ERR;
        }

        // calculating the value of the exponent 
        while (idx < len && input[idx] != '\n') {
            if (input[idx] < '0' || input[idx] > '9') {       
                return ERR;
            }
            exp *= 10;
            exp += (int)(input[idx] - '0');
            idx++;
        }
    } 

    // if there is an exponential notation in terms of 'E' or 'e'
    if (exp_flag == 1){ 
        for (int i = 0; i < exp; i++) {

            if (exp_sign == -1)   // for negative exponent divide by the respective power of 10
                float_val /= 10;
            
            else                 // for positive exponent, multiply by the respective power of 10
                float_val *= 10;
        }
    }

    float_val *= sign_flag;
    *f = float_val;

    return OK;
}

// function to print a floating point number with 6 digits of precision after the decimal point, using sysycall
int printFlt(float f){

    char output[BUFSIZE];
    int num_char = 0;
    float float_val = f;

    if (float_val < 0) {
        output[num_char++] = '-';
        float_val *= -1;
    }

    // first printing the integral part
    int int_part = (int)float_val;

    if (int_part == 0) {
        output[num_char++] = '0';
    }

    while (int_part > 0) {
        output[num_char++] = (int_part % 10) + '0';
        int_part /= 10;
        if (num_char >= BUFSIZE) {  // if the integer to be printed is too large to fit in the buffer, we return ERR
            return ERR;
        } 
    }

    int j = (output[0] == '-') ? 1 : 0;
    int k = num_char - 1;

    while(j < k){
        char temp = output[j];
        output[j++] = output[k];
        output[k--] = temp;
    }

    // after printing the integral part, add the decimal point to output char array
    output[num_char++] = '.';

    if (num_char >= BUFSIZE)     // if the buffer can't accomodate the entire float value, return ERROR
        return ERR;

    // handling the printing of fractional part (upto 6 digit precision)
    float_val -= (int)float_val;
    for (int i = 0; i < PRECISION; i++){
        float_val *= 10;
    }

    int fractional = (int)float_val;   // truncate the fractional part to only 6 digits after decimal
 
    if (fractional == 0){             // if the float has no fractional part, append 6 zeroes after the decima;
        for (int i = 0; i < PRECISION; i++)
            output[num_char++] = '0';  
    }

    else{                             // printing the fractional part if it is not zero
        
        j = num_char;

        for (int i = 0; i < PRECISION; i++){
            output[num_char++] = (fractional%10) + '0';
            fractional /= 10;
            if (num_char >= BUFSIZE){
                return ERR;
            }
        }

        k = num_char - 1;
        while(j < k){
            char temp = output[j];
            output[j++] = output[k];
            output[k--] = temp;
        }
    }

    output[num_char] = '\0';

    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(output), "d"(num_char)
    );
    
    return num_char;              // return the no of characters printed
}