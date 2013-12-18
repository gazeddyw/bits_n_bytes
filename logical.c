
/*
 * Logical??
 */

#include <stdio.h>

void logic_1();
void logic_2();

int main()
{
    puts("");
    
    logic_1();
    
    puts("");
    
    logic_2();
    
    puts("");
    
    return 0;
}


void logic_1()
{
    int logic = (!(1 && !(0 || 1)));
    if (logic)
        puts(" 1 ");
    else
        puts(" 0 ");    
}


void logic_2()
{
    int logic = (0 || 1);   // 0 || 1 always evaluates to TRUE (1) 
    if (logic)
        puts(" 1 ");
    else
        puts(" 0 ");
    
}