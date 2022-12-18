// TEST FILE 3

// Testing of arrays, loops (simple as well as nested)

// function for matrix multiplication
float frobenius_norm(int **A, int n){
    // matrix A: n x n

    float norm = 0.0;
    // nested for loop
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            norm += A[i][j]*A[i][j];
        }
    }
    norm = sqrt(norm);
    return norm;
}

int main () {

    int n = 3;
    int A[3][3];                // 2D array declaration
    int i,j;
    int k = 1;

    /*
     In order to test the correctness of generated TAC for array operations,
     We test the above functions using an array initialized uisng loops.
     Direct initialization of arrays of the form :-
        int A[2][2] = {{1, 2}, {3, 4}} 
     is not supported by tinyC and will give errors during translation.
    */
   
    for (i=0; i<n; i++){                        // Initialize 2D array using loops

        for (j=0; j<n; j++){

            A[i][j] = k;
            k++;
        }
    }

    float norm = frobenius_norm(A, n);         // call function with 2d array passed as input
    return 0;
}

