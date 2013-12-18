
/*
 * A random number key generator
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_ASCII 33
#define MAX_ASCII 93

char gen_rand_num();
char key(char arr[], int kl);

int main(int argc, char *argv[])
{
        srand((unsigned int)time(0));
        
        int key_len = 75;   // use unistd.h & atoi() to get key_len from cmd...
        
        char array[key_len];
        key(array, key_len);
        printf("%s", array);
        puts("");
        
        return 0;
}

char key(char arr[], int kl)
{
        int i;
        for (i = 0; i < kl; ++i) {
                arr[i] = gen_rand_num();
                //printf("%c %d ", arr[i], arr[i]);
        }
        //puts("");
        return *arr;
}

char gen_rand_num()
{
        char rand;
        while (((rand = (MIN_ASCII + (random() % MAX_ASCII))) == '"') || 
                (rand == '\''))
                continue;
        
        return rand;
}
