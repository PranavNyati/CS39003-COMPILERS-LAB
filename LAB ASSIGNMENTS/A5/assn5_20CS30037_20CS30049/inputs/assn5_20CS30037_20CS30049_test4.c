// TEST FILE 4

// Testing of typecasting and nested if-else

int main(){

    int a = 4;
    int i;
    int sum = 0;
    float arr[4], temp;                       // define a float array and initialize with random values

    /* 
        element wise initialization done here
        This is bcoz array initialization not supported by tinyC
    */
    arr[0] = 40.23;                          
    arr[1] = 19.75;
    arr[2] = 32.03;
    arr[3] = 89.95;

    int round_arr[4];

    for (i = 0; i < a; i++){        

        /*
            We define a custom round off function
            if number is > 50.0 and residue on typecast >= 0.5, round off to next integer
            else, round off to prev integer
        */

        temp = arr[i];
        if (temp > 50.0){

            // nested if-else block
            if ((temp - (int)temp) >= 0.5){     // float to int typecasting

                round_arr[i] = (int)temp + 1;  
            }
            else{
                round_arr[i] = (int)temp;
            }
        }
        else{
            round_arr[i] = (int)temp;
        }
    }

    return 0;
}

