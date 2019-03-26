#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "md4c.h"

char* readfile(char *filename) {
    FILE *handler = fopen(filename, "r");

    if (!handler) {
        return NULL;
    }

    fseek(handler, 0, SEEK_END);
    int len = ftell(handler);
    rewind(handler);

    char *buffer = (char*) malloc(sizeof(char) * (len + 1) );
    int bytesRead = fread(buffer, sizeof(char), len, handler);
    buffer[len] = '\0';

    if (len != bytesRead) {
        free(buffer);
        buffer = NULL;
    }

    fclose(handler);
    return buffer;
}

int enter_block(MD_BLOCKTYPE type, void* details, void* userdata) {
    return 0;
}

int leave_block(MD_BLOCKTYPE type, void* details, void* userdata) {
    return 0;
}

int enter_span(MD_SPANTYPE type, void* details, void* userdata) {
    return 0;
}

int leave_span(MD_SPANTYPE type, void* details, void* userdata) {
    return 0;
}

int printText(MD_TEXTTYPE type, const MD_CHAR* text, MD_SIZE size, void* userdata) {
    return 0;
}


int main() {
    char *input = readfile("sample1.md");
    if (!input) {
        return 1;
    }

    int len = strlen(input);

    MD_PARSER parser = {
        .enter_block = enter_block,
        .leave_block = leave_block,
        .enter_span = enter_span,
        .leave_span = leave_span,
        .text = printText
    };


    {
        int iterations = 1000;

        clock_t start = clock();
        for (int i = 0; i < iterations; ++i) {
            if (md_parse(input, len, &parser, NULL) != 0) {
                puts("md4c failed");
                return 1;
            }
        }
        clock_t diff = clock() - start;
        
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("%6d iterations = %3d.%03ds\n", iterations, msec/1000, msec%1000);
    }


    {
        int iterations = 10000;

        clock_t start = clock();
        for (int i = 0; i < iterations; ++i) {
            if (md_parse(input, len, &parser, NULL) != 0) {
                puts("md4c failed");
                return 1;
            }
        }
        clock_t diff = clock() - start;
        
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("%6d iterations = %3d.%03ds\n", iterations, msec/1000, msec%1000);
    }


    {
        int iterations = 100000;

        clock_t start = clock();
        for (int i = 0; i < iterations; ++i) {
            if (md_parse(input, len, &parser, NULL) != 0) {
                puts("md4c failed");
                return 1;
            }
        }
        clock_t diff = clock() - start;
        
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("%6d iterations = %3d.%03ds\n", iterations, msec/1000, msec%1000);
    }

    return 0;
}
