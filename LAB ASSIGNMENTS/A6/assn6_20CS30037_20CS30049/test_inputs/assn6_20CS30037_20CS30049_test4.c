/*
    Compilers Lab Assignment - 6
    Group Members :-
        Pranav Nyati - 20CS30037
        Shreyas Jena - 20CS30049
*/

// TEST FILE - 4

// helper functions to read an integer from user, print and integer and print a string
int printStr (char *ch);
int printInt (int n);
int readInt (int *eP);


// function to calculate the GCD of two numbers
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

int main()

{
    int a, b;
    int gcd_val;
    int err;
    printStr("Enter the value of a: \n");
    a = readInt(&err);
    printStr("Enter the value of b: \n");
    b = readInt(&err);

    // print the GCD of a and b
    gcd_val = gcd(a, b);

    printStr("\n");
    printStr("The GCD of ");
    printInt(a);
    printStr(" and ");
    printInt(b);
    printStr(" is: ");
    printInt(gcd_val);
    printStr("\n");

    printStr("TEST 4 COMPLETED\n");

    return 0;

}