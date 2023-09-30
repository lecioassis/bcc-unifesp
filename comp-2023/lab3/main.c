#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    Buffer *buffer = allocate_buffer(filename);

    char ch;
    while ((ch = get_next_char(buffer)) != EOF) {
        // Faça o processamento desejado com o caractere 'ch'
        putchar(ch);
    }

    deallocate_buffer(buffer);

    return EXIT_SUCCESS;
}