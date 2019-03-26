#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cmark.h"

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


int main() {
    char *input = readfile("sample1.md");
    if (!input) {
        return 1;
    }

    int len = strlen(input);

    {
        int iterations = 1000;

        clock_t start = clock();
        for (int i = 0; i < iterations; ++i) {
            char *output = cmark_markdown_to_html(input, len, CMARK_OPT_DEFAULT);

            if (output) {
                free(output);
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
            char *output = cmark_markdown_to_html(input, len, CMARK_OPT_DEFAULT);

            if (output) {
                free(output);
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
            char *output = cmark_markdown_to_html(input, len, CMARK_OPT_DEFAULT);

            if (output) {
                free(output);
            }
        }
        clock_t diff = clock() - start;
        
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("%6d iterations = %3d.%03ds\n", iterations, msec/1000, msec%1000);
    }

    return 0;
}