#include "wordsgenerator.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

void print_usage(const char *prog);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        print_usage(argv[0]);
        return 1;
    }

    bool verbose = false;
    bool output = false;
    char *file = NULL;
    uint16_t count;

    int opt;
    while ((opt = getopt(argc, argv, ":c:vo:")) != -1)
    {
        switch (opt)
        {
        case 'c':
            count = atol(optarg);
            break;
        case 'v':
            verbose = true;
            break;
        case 'o':
            output = true;
            file = optarg;
            break;
        default:
            print_usage(argv[0]);
            return 1;
        }
    }

    srand((unsigned)time(NULL));

    words *w = words_generator_create(count);

    if (verbose)
        words_generator_print(w);
    if (output)
        words_generator_export(w, file);

    words_generator_destroy(w);
    return 0;
}

// receives argv[0]
void print_usage(const char *prog)
{
    printf("Usage: %s [-c count] [-v] [-o file]\n", prog);
    printf("Options:\n");
    printf("  -c count   Number of iterations (max: 10000)\n");
    printf("  -v         Enable verbose output\n");
    printf("  -o file    Write output to file\n");
}