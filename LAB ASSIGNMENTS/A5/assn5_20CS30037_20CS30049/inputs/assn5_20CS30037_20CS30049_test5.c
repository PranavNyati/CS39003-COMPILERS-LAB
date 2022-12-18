// TEST FILE 5

// Testing of pointers and recursive functions

// function declaration for swapping two float values
void swap_floats(float* first, float* second) {

    float temp = *first;
    *first = *second;
    *second = temp;
    return;
}

// Recursive functions To calculate factorial 
int fact (int n) {                               
    if (n == 0) 
        return 1; 
    return n * fact(n-1); 
} 

int main(){
    
    float x = 37.49;
    float y = 49.37;
    float *ptr1, *ptr2;
    ptr1 = &x;
    ptr2 = &y;

    swap_floats(ptr1, ptr2);        // call function to swap two float values

    int n = 5;
    int fact_n = fact(n);           // Call recursive function to compute factorial

    return 0;
}