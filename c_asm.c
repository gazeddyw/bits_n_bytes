/*
 *
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int answer, operand = 8;

	asm ("shl $2, %0" : "=r" (answer) : "r" (operand) : "cc");

	printf("%d\n", answer);

	return 0;
}

