/************************************************
 *
 * Displays a number in binary
 *
 ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>         /* for getopt_long() */
#include <string.h>
#include <time.h>
#include <limits.h>


// Struct to store command line options
struct globalArgs_t
{
    int num;                /* -d option */
    char **inputFiles;      /* input files */
    int numOfInputFiles;    /* # of input files */
    int randomize;          /* --randomize option */
}
globalArgs;

// option string
static const char *optString = "d:h";

// Array of option structs to hold info about long options supported
static const struct option longOpts[] = {
    { "num", required_argument, NULL, 'd' },
    { "rand-int", no_argument, NULL, 0 },
    { "help", no_argument, NULL, 'h' },
    { NULL, no_argument, NULL, 0 }
};


// function prototypes
void display_usage(void);
int generate_random_int(void);


int main(int argc, char *argv[])
{
    int opt;
    int longIndex;

    /* Initialise globalArgs members */
    globalArgs.num = 0;
    globalArgs.inputFiles = NULL;
    globalArgs.numOfInputFiles = 0;
    globalArgs.randomize = 0;

    while((opt = getopt_long(argc, argv, optString,
                                longOpts, &longIndex)) != -1)
    {
        switch (opt)
        {
        case 'd':
            globalArgs.num = atoi(optarg);
            break;

        case 'h':       /* fall-through intentional */
        case '?':
            display_usage();
            break;

        case 0:         /* long option without a short equivalent */
            if (strcmp("rand-int", longOpts[longIndex].name) == 0)
                globalArgs.randomize = 1; 
            break;

        default:
            break;
        }
    }

    globalArgs.inputFiles = argv + optind;
    globalArgs.numOfInputFiles = argc - optind;

    if (globalArgs.randomize)
        globalArgs.num = generate_random_int();

    // print number in binary
    for (int i = ((sizeof(int) * 8) - 1); i >= 0; i--)
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


int generate_random_int(void)
{
    srand(time(0));
    int random = (rand() * INT_MAX);

    return random;
}
