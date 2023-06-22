#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(FILE *source, FILE *destination, char option) {
    char ch;

    switch(option) {
        case 'u':
            while ((ch = fgetc(source)) != EOF) {
                fputc(toupper(ch), destination);
            }
            break;

        case 'l':
            while ((ch = fgetc(source)) != EOF) {
                fputc(tolower(ch), destination);
            }
            break;

        case 's':
            ch = fgetc(source);
            if (isalpha(ch)) {
                fputc(toupper(ch), destination);
            } else {
                fputc(ch, destination);
            }

            while ((ch = fgetc(source)) != EOF) {
                if (ch == '.' || ch == '!' || ch == '?') {
                    while ((ch = fgetc(source)) != EOF && isspace(ch));
                    if (ch != EOF) {
                        fputc(toupper(ch), destination);
                    }
                } else {
                    fputc(tolower(ch), destination);
                }
            }
            break;

        default:
            while ((ch = fgetc(source)) != EOF) {
                fputc(ch, destination);
            }
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_file> <destination_file> [option]\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL) {
        printf("Error creating the destination file.\n");
        fclose(source);
        return 1;
    }

    char option = 'n';
    if (argc > 3) {
        option = argv[3][0];
    }

    copyFile(source, destination, option);

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}
