/*
Program name: doSomething.cpp
Programmer: Tyler Davies
Date: 9-11-21
Version: 2.0
Description: This program rewrites a given function which used pass-by-reference to now make use of pointers
             instead. It then demonstates the newly created function in a complete program. The complete
             program will prompt the user for two variables, pass the address of both using the address
             operator, and then outputs to the screen the new values and their sum.
*/

#include<iostream>

using namespace std;

//Function prototypes (parameter variable names not required in the prototype).
void getValues(int*, int*);
int doSomething(int*, int*);
void printValues(const int*, const int*, const int*);

int main()
{
    int value1, value2, newValsSum;

    getValues(&value1, &value2);
    newValsSum = doSomething(&value1, &value2);
    printValues(&value1, &value2, &newValsSum);

    exit(0);
}

//This function prompts the user for two integer values.
void getValues(int *val1, int *val2)
{
    cout << "Please enter an integer value:" << endl;
    cin >> *val1;
    cout << "Please enter another integer value:" << endl;
    cin >> *val2;
}

/*
This function used to use pass-by-reference, but now uses pointers instead. It takes two values,
swaps them while multiplying those values by ten, and then returns the sum of those new values.
*/
int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return (*x + *y);   //Parenthesis not included in the original function, but helps visually.
}

/*
This function takes the new values and their sum, and displays them in sentences on the output screen.
Its parameters are constant values, because it is only outputting the information; no changes are to be made.
*/
void printValues(const int *val1, const int *val2, const int *valsSum)
{
    cout << endl << "The second value times ten is equal to " << *val1 << "." << endl;
    cout << "The first value times ten is equal to " << *val2 << "." << endl;
    cout << "The sum of the two new values is equal to " << *valsSum << "." << endl;
}