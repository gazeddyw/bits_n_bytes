
/*
 * POINTERS!! :P
 */

#include <stdio.h>

void point();

int main()
{
    puts("");
    
    point();
    
    puts("");
    
    return 0;
}


void point()
{
    int a[] = {12, 13, 14, 15 ,16};
    
    int *aptr = &a[2];
    
    printf("%p\n", aptr);
    
    printf("%d\n", *aptr);
    
}
