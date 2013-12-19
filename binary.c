/************************************************
 *
 * Displays a number in binary
 *
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


// Struct to store command line options
struct globalArgs_t
{
    int num;                /* -d option */
    char **inputFiles;      /* input files */
    int numOfInputFiles;    /* # of input files */
}
globalArgs;

// option string
static const char *optString = "d:h";


// function prototypes
void display_usage(void);


int main(int argc, char *argv[])
{
    int opt;

    /* Initialise globalArgs members */
    globalArgs.num = 0;
    globalArgs.inputFiles = NULL;
    globalArgs.numOfInputFiles = 0;

    while((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
        case 'd':
            globalArgs.num = atoi(optarg);
            break;
        case 'h':
            display_usage();
            break;
        case '?':
            display_usage();
            break;
        default:
            break;
        }
    }

    globalArgs.inputFiles = argv + optind;
    globalArgs.numOfInputFiles = argc - optind;

    // print number in binary
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        int mask = 1 << i;
        if (globalArgs.num & mask)
            printf("1");
        else
            printf("0");
    }

    printf("\n");

    return 0;
}


void display_usage(void)
{
    puts("binary - displays a decimal number in binary");
    exit(EXIT_FAILURE);
}

