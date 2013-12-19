#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;
    
    printf("x is %d\n", &x);
    printf("y is %d\n", &y);
    printf("Swapping...\n");
    swap(x, y);
    printf("Swapped!\n");
    printf("x is %d\n", x);
    printf("y is %d\n", y);
    
    return 0;
}

/**
 * Swap argument's values
 */
void swap (int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

