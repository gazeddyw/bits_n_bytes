#include <stdio.h>

void increment(int *num);

int main(void)
{
    int x = 1;
    
    printf("x is %d\n", x);
    printf("Incrementing...\n");
    increment(&x);
    printf("Incremented!\n");
    printf("x is %d\n", x);
    
    return 0;
}

/**
 * Increments x.
 */
void increment (int *num)
{
    (*num)++;   // Parentheses are required here as operators such as * and ++
                // associate right to left. Alt. ++*num; could be used here.
}

