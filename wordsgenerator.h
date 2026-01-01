#ifndef WORDSGENERATOR_H
#define WORDSGENERATOR_H

#include <stdint.h>

typedef struct _words words;

words *words_generator_create(uint16_t);
void words_generator_print(words *);
void words_generator_export(words *, const char *);
void words_generator_destroy(words *);

#endif