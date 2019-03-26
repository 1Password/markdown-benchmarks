#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "html.h"

uint8_t* readfile(char *filename, int *len) {
    FILE *handler = fopen(filename, "r");

    if (!handler) {
        return NULL;
    }

    fseek(handler, 0, SEEK_END);
    *len = ftell(handler);
    rewind(handler);

    uint8_t *buffer = (uint8_t*) malloc(sizeof(uint8_t) * ((*len) + 1) );
    int bytesRead = fread(buffer, sizeof(uint8_t), *len, handler);
    buffer[*len] = '\0';

    if (*len != bytesRead) {
        free(buffer);
        buffer = NULL;
    }

    fclose(handler);

    return buffer;
}


int main() {
    int len = 0;
    uint8_t *input = readfile("sample1.md", &len);
    if (!input) {
        return 1;
    }

    {
        int iterations = 1000;

        clock_t start = clock();
        for (int i = 0; i < iterations; ++i) {
            hoedown_renderer *renderer = hoedown_html_renderer_new(0, 0);
            hoedown_document *document = hoedown_document_new(renderer, 0, 16);
            hoedown_buffer *html = hoedown_buffer_new(len * 3);
            hoedown_document_render(document, html, input, len);

            // (void)fwrite(html->data, 1, html->size, stdout);

            hoedown_buffer_free(html);
            hoedown_document_free(document);
            hoedown_html_renderer_free(renderer);
        }
        clock_t diff = clock() - start;
        
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("%6d iterations = %3d.%03ds\n", iterations, msec/1000, msec%1000);
    }

    {
        int iterations = 10000;

        clock_t start = clock();
        for (int i = 0; i < iterations; ++i) {
            hoedown_renderer *renderer = hoedown_html_renderer_new(0, 0);
            hoedown_document *document = hoedown_document_new(renderer, 0, 16);
            hoedown_buffer *html = hoedown_buffer_new(len * 3);
            hoedown_document_render(document, html, input, len);

            // (void)fwrite(html->data, 1, html->size, stdout);

            hoedown_buffer_free(html);
            hoedown_document_free(document);
            hoedown_html_renderer_free(renderer);
        }
        clock_t diff = clock() - start;
        
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("%6d iterations = %3d.%03ds\n", iterations, msec/1000, msec%1000);
    }

    {
        int iterations = 100000;

        clock_t start = clock();
        for (int i = 0; i < iterations; ++i) {
            hoedown_renderer *renderer = hoedown_html_renderer_new(0, 0);
            hoedown_document *document = hoedown_document_new(renderer, 0, 16);
            hoedown_buffer *html = hoedown_buffer_new(len * 3);
            hoedown_document_render(document, html, input, len);

            // (void)fwrite(html->data, 1, html->size, stdout);

            hoedown_buffer_free(html);
            hoedown_document_free(document);
            hoedown_html_renderer_free(renderer);
        }
        clock_t diff = clock() - start;
        
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("%6d iterations = %3d.%03ds\n", iterations, msec/1000, msec%1000);
    }

    return 0;
}