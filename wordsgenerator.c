#include "wordsgenerator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_COUNT 10000
#define MAX_LINE 150

struct _words
{
    uint16_t size;
    char **values;
};

void generate_word(char *buffer, size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        buffer[i] = 'a' + (rand() % 26);
    }
    buffer[length - 1] = 0;
}

words *words_generator_create(uint16_t count)
{
    if (count > MAX_COUNT)
        count = MAX_COUNT;
    printf("Creating %u words.\n", count);

    words *w = malloc(sizeof(*w));
    w->size = count;
    w->values = calloc(w->size, sizeof(char *));

    char buffer[MAX_LINE];
    const uint8_t shortest_word = 2;
    const uint8_t longest_word = 15;
    for (uint16_t i = 0; i < w->size; i++)
    {
        generate_word(buffer, shortest_word + (rand() % (longest_word - shortest_word + 1)));
        char *new_word = malloc(strlen(buffer) + 1);
        strcpy(new_word, buffer);
        w->values[i] = new_word;
    }

    return w;
}

void words_generator_print(words *words)
{
    printf("\n--- Start Words ---\n\n");
    for (uint16_t i = 0; i < words->size; i++)
        printf("%s\n", words->values[i]);

    printf("\n--- End Words ---\n\n");
}

void words_generator_export(words *words, const char *file_name)
{
    printf("\n--- Exporting ---\n\n");
    FILE *fptr;

    if (file_name == NULL)
        file_name = "file.txt";
    // Creating file using fopen()
    // with access mode "w"
    fptr = fopen(file_name, "w");

    // checking if the file is created
    if (fptr == NULL)
    {
        printf("The file is not opened.\n");
        return;
    }

    printf("The file is created successfully.\n");

    for (uint16_t i = 0; i < words->size; i++)
        fprintf(fptr, "%s\n", words->values[i]);

    fclose(fptr);
}

void words_generator_destroy(words *words)
{
    if (!words)
        return;

    for (uint16_t i = 0; i < words->size; i++)
        free(words->values[i]);

    free(words->values);
    free(words);
}