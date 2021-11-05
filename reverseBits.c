#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void printBits(int x);
void reverseBits(int x);

int main(void)
{
    unsigned int x;
    printf("Enter a non-negative integer: ");
    scanf("%d", &x);
    printBits(x);
    printf("\n");
    reverseBits(x);
} 

// print the bits of x in order
void printBits(int x) {
    // find the number of bits in x
    int len = sizeof(x) * 8;
    // declare an array of booleans for the bits
    bool bits[len];
    // loop through the bits of x
    for(int i = 0; i < len; i++) {
        // find the ith power of 2 by shifting 1 left by i bits (e.g. 2^0 = 1, 2^1 = 10, 2^2 = 100)
        int ithPowerOf2 = 1 << i;
        // find if x shares a bit with the ith power of 2
        int shared = ithPowerOf2 & x;
        // shift shared left by i bits so the result is either 1 or 0
        int currentBit = shared >> i;
        // assign the bit from right to left (least significant to most significant)
        bits[len - i - 1] = currentBit;
    }
    // print the bits in order
    for(int i = 0; i < len; i++) {
        printf("%d", bits[i]);
    }
}

// print the bits of x in reverse order
void reverseBits(int x) {
    // find the number of bits in x
    int len = sizeof(x) * 8;
    // declare an array of booleans for the bits
    bool bits[len];
    // loop through the bits of x
    for(int i = 0; i < len; i++) {
        // find the ith power of 2 by shifting 1 left by i bits (e.g. 2^0 = 1, 2^1 = 10, 2^2 = 100)
        int ithPowerOf2 = 1 << i;
        // find if x shares a bit with the ith power of 2
        int shared = ithPowerOf2 & x;
        // shift shared left by i bits so the result is either 1 or 0
        int currentBit = shared >> i;
        // since the bits are being determined from least significant to most significant (right to left),
        // then assigning them from left to right will reverse them
        bits[i] = currentBit;
    }
    // print the bits in reverse order
    for(int i = 0; i < len; i++) {
        printf("%d", bits[i]);
    }
}
