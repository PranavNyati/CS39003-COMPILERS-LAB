/*
    Compilers Lab Assignment - 6
    Group Members :-
        Pranav Nyati - 20CS30037
        Shreyas Jena - 20CS30049
*/

// TEST FILE - 3
int printStr (char *ch);
int printInt (int n);
int readInt (int *eP);

 // Recursive function that will return the maximum sum of a contiguous subarray of the array arr
int maxSubArraySum(int arr[], int size)      
{
    int max_sum = -99999;
    int current_max = 0;
    int i;

    for(i = 0 ; i < size ; i++)
    {
        current_max = current_max + arr[i];

        if(max_sum < current_max)
            max_sum = current_max;

        if(current_max < 0)
            current_max = 0;
    }

    return max_sum;
}


int main()
{
    int n, i, err;
    int arr[40];
   
    printStr("\nEnter the size of an integer array: (size less than 40)\n"); 
    n=readInt(&err);
    
    printStr("\nEnter the elements of the array one by one, in seperate lines\n");
    
    for(i = 0; i < n; i++)
    {
        arr[i]=readInt(&err);
    }

    int sum;
    sum = maxSubArraySum(arr, n);
    
    printStr("\nLargest possible sum of a contiguous subarray  of the given array is: ");
    printInt(sum);
    printStr("\n");
    
    printStr("TEST 3 COMPLETED\n");
    
    return 0;
}