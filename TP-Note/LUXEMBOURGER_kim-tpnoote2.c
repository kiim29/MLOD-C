
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE_MAX 5

typedef struct {
    void *next;
    unsigned int chunkSize;
    char *chunk;
} Chunk;

typedef Chunk* String;

