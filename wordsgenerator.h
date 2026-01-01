#ifndef WORDSGENERATOR_H
#define WORDSGENERATOR_H

#include <stdint.h>

typedef struct _words words;
typedef enum {
    MODE_NONE = 0,
    MODE_UPPER,
    MODE_LOWER,
    MODE_CAPITALIZED
} words_mode;

words *words_generator_create(uint16_t, const words_mode);
void words_generator_print(words *);
void words_generator_export(words *, const char *);
void words_generator_destroy(words *);

#endif