#include <stdio.h>
#include <stdlib.h>
// declare functions
int getOr(int a, int b);
int getAnd(int a, int b);
int getXor(int a, int b);


int main(void)
{
    // declare and input integers
    unsigned int x, y;
    printf("Enter 2 non-negative integers: ");
    scanf("%d %d", &x, &y);
    // declare and initialize array of function pointers: OR, AND, XOR
    int (*functions[3])(int, int) = {getOr, getAnd, getXor};
    // declare the operator number variable
    int op;
    printf("Enter 0 for OR, 1 for AND, 2 for XOR: ");
    do {
        // get the operator number
        scanf("%d", &op);
        // if the operator number is not between 0 or 2, then ask again
        if((op < 0) || (op > 2)) {
            printf("Please only enter a number between 0 and 2: ");
        }
        else {
            // call the requested function using the inputted numbers
            printf("Result: %d", functions[op](x, y));
        }
    // keep asking for a number until something between 0 and 2 is inputted
    } while((op < 0) || (op > 2));
} 

// bitwise or
int getOr(int a, int b) {
    return a | b;
}
// bitwise and
int getAnd(int a, int b) {
    return a & b;
}
// bitwise xor
int getXor(int a, int b) {
    return a ^ b;
}



