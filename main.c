#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_characters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    int char_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        char_count++;
    }

    fclose(file);
    printf("×Ö·ûÊý£º%d\n", char_count);
}

void count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    int word_count = 0;
    char ch, prev_ch = ' ';
    while ((ch = fgetc(file)) != EOF) {
        if ((ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') && 
            (prev_ch != ' ' && prev_ch != ',' && prev_ch != '\n' && prev_ch != '\t')) {
            word_count++;
        }
        prev_ch = ch;
    }

    // If the last character is not a space, count the last word
    if (prev_ch != ' ' && prev_ch != ',' && prev_ch != '\n' && prev_ch != '\t') {
        word_count++;
    }

    fclose(file);
    printf("µ¥´ÊÊý£º%d\n", word_count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [-c|-w] <input_file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-c") == 0) {
        count_characters(argv[2]);
    } else if (strcmp(argv[1], "-w") == 0) {
        count_words(argv[2]);
    } else {
        fprintf(stderr, "Invalid parameter. Use -c for characters count and -w for words count.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

