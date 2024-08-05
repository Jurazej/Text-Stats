#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_stats(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int characters = 0, words = 0, lines = 0;
    int in_word = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        characters++;

        if (c == '\n') {
            lines++;
        }

        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    fclose(file);

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    print_stats(argv[1]);
    return 0;
}
