/*
    Compilers Lab Assignment - 6
    Group Members :-
        Pranav Nyati - 20CS30037
        Shreyas Jena - 20CS30049
*/

// TEST FILE - 5


// helper functions to read an integer from user, print and integer and print a string
int printStr (char *ch);
int printInt (int n);
int readInt (int *eP);

// Forward Function declaration without the body for fibonacci function
int fibonacci_recur(int n);

int main() {
    int n, err, i;
    
    printStr("Enter the number of terms n in the fibonacci series: (Keep n < 25)\n");
    n = readInt(&err);

    int fib_arr[50];
    
    for (i = 0; i < n; i++) {
        fib_arr[i] = fibonacci_recur(i);
    }
    printStr("\n");
    printStr("The first ");
    printInt(n);
    printStr(" terms of the fibonacci series are: \n");

    for (i = 0; i < n-1; i++) {
        printInt(fib_arr[i]);
        printStr(", ");
    }
    printInt(fib_arr[n-1]);
    printStr("\n");

    printStr("TEST 5 COMPLETED\n");

    return 0;
}


// Function to calculate the nth fibonacci number using recursion
int fibonacci_recur(int n) {
    if (n == 0) {
        return 0;
    } 
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci_recur(n - 1) + fibonacci_recur(n - 2);
    }
}