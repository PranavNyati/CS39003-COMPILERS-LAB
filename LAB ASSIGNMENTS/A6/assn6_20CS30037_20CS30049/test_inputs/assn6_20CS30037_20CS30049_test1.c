/*
    Compilers Lab Assignment - 6
    Group Members :-
        Pranav Nyati - 20CS30037
        Shreyas Jena - 20CS30049
*/

// TEST FILE - 1

// Testing of global variable declaration
int glbl_idx = 0;                         
float MAX_ARR_SIZE = 100;                 


// helper functions to read an integer from user, print and integer and print a string
int printStr (char *ch);
int printInt (int n);
int readInt (int *eP);

// function for binary search for a key in an integer array
int binarySearch (int int_arr[], int key, int left, int right) {   
    while (left <= right) {
        int mid = (left + right) / 2;
        if (int_arr[mid] == key) {                  // Testing of if-else-if-else ladder                                        
            return mid;                            
        } else if (int_arr[mid] < key) {            
            left = mid + 1;
        } else {   
            right = mid - 1;
        }
    }
    return -1;                              // Testing return statement
}

int main() {
    
    glbl_idx *= 2;                        

    int arr_1[15];                              // Testing 1-D array declaration
    int i, n, err;                                // Testing variable declarations

    // Testing reading of array elements from user
    printStr("Enter 15 array elements in ascending order in seperate lines:\n");
    for (i = 0; i < 15; i++) {
        arr_1[i] = readInt(&err);                 // Testing readInt
    }

    // Testing print numbers
    printStr("The array elements taken as user input are: \n");
    for (i = 0; i < 15; i++) {              // Testing for loop
        printInt(arr_1[i]);                     // Testing printInt
        printStr(" ");                      // Testing printStr     
    }
    printStr("\n");

    int my_key;
    printStr("Enter the number to search for in the array: \n");
    my_key = readInt(&err);

    int start = 0, end = 9;

    int key_idx = binarySearch(arr_1, my_key, start, end);
    if (key_idx == -1) {
        printStr("The given key is not present in the array.\n");
    } else { 
        printStr("The given key is present in the arrray at index: ");
        printInt(key_idx);
    }
    printStr("\n");

    printStr("TEST 1 COMPLETED\n");

    return 0;
}