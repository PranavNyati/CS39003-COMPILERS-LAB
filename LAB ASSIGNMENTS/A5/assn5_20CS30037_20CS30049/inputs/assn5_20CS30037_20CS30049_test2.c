// TEST FILE 2

// Testing of function calls


// function (with two arguments) to perform BITWISE AND on two integers
int bitwise_and(int a, int b)        
{
    int and_op = a&b;
    return and_op;
}
 
// function (with two arguments) to subtract two double values, type cast the result to int and return result
int subtract_dbl(double a, double b)         
{
    int c;
    c = a-b;    // double value type-casted to int
    return c;
}

// function (with one argument) to perform NOT operation on integer
int bitwise_not(int a)        
{
    int neg_op = ~a;
    return neg_op;
}

// function (with no arguments) to initialize an array and then add its elements
int arraySum(){                     

    int i;
    int arr[4];                          // 1D array declaration
    int sum = 0;

    for (i=0; i<4; i++){                // checking array indexing operations
        arr[i] = 3*i;
        sum = sum + arr[i];
    }

    return sum;
}

void main(){

    int p = 8;
    int q = 5;
    int r;
    double x = 1.4;

    r = bitwise_and(p, q);
    int s = subtract_dbl(q, x);
    x = bitwise_not(p);          
    int arr_sum = arraySum();

    return;
}