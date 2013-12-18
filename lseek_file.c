/*
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


int pop(unsigned int x);


int main(int argc, char* argv[])
{
    char *filepath = "";
    int seek_pos = 0;

    char ch;
    while ((ch = getopt(argc, argv, "f:s:")) != EOF) {
        switch (ch) {
            case 'f':
                filepath = optarg;
                break;
            case 's':
                seek_pos = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Unknown option: %s\n", optarg);
                return 1;
        }
    }

    argc -= optind;
    argv += optind;

    if (seek_pos < 0)
        seek_pos = 0;

    if (filepath[0]) {
        printf("File: %s\n", filepath);
    }

    FILE *file_ptr;
    file_ptr = fopen(filepath, "r");

    if (file_ptr == 0)
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));

    while (!feof(file_ptr)) {
        char c = fgetc(file_ptr);
        if (c == EOF) {
            printf("%d\n", c);
        }
        else {
            printf("%c", c);
        }
    }

    lseek(fileno(file_ptr), seek_pos, SEEK_SET);

    //rewind(file_ptr);
    printf("%d ", fgetc(file_ptr));
    
    printf("\n");
    fclose(file_ptr);
    printf("pop: %d\n", pop(seek_pos));
    return 0;
}

/*
 * Algorithm for counting number of 1 bits in an int
 * Shift right & subtract method
 */
int pop(unsigned int x)
{
    int sum;
    
    sum = x;
    while (x != 0) {
        x = x >> 1;
        sum = sum - x;
    }
    return sum;
}

