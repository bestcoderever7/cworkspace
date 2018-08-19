#include <stdio.h>
#include <math.h>

//1. Complete the functions below so that they print the individual bits of the passed in argument.
//   Use the main function to test them.

void print8BitBinary(unsigned char v) {
    for(int i = 0; i < 8; i++)
    {
        unsigned char p = pow(2, i);
        printf("%i", (v & p)>>i);
        printf("%s", "\n");
    }
}

void print16BitBinary(unsigned short v){
    unsigned char *byte = (unsigned char*) &v;
    print8BitBinary(*byte);
    byte++;
    print8BitBinary(*byte);
}

void print32BitBinary(unsigned int v){
    unsigned char *half = (unsigned char *) &v;
    print16BitBinary(*half);
    half++;
    print16BitBinary(*half);
}

void print64BitBinary(unsigned long v){
    unsigned char *half = (unsigned char *) &v;
    print32BitBinary(*half);
    half++;
    print32BitBinary(*half);
}

int main(int argc, char** argv){
    print64BitBinary(100000000);
    return 0;
}