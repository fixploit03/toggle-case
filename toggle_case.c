#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toggle_case(char *word) {
    for (int i = 0; word[i]; i++) {
        if (isupper(word[i])) {
            word[i] = tolower(word[i]);
        } else if (islower(word[i])) {
            word[i] = toupper(word[i]);
        }
    }
}

void generate_toggle_case(char *word) {
    int len = strlen(word);
    unsigned int num_combinations = 1 << len; // 2^len combinations

    for (unsigned int i = 0; i < num_combinations; i++) {
        char temp_word[len + 1];
        strcpy(temp_word, word);

        for (int j = 0; j < len; j++) {
            if (i & (1 << j)) {
                temp_word[j] = toupper(temp_word[j]);
            } else {
                temp_word[j] = tolower(temp_word[j]);
            }
        }

        printf("%s\n", temp_word);
    }
}

int main() {
    FILE *file = fopen("wordlist.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char word[100];
    while (fgets(word, sizeof(word), file)) {
        // Remove newline character if exists
        word[strcspn(word, "\n")] = 0;

        generate_toggle_case(word);
    }

    fclose(file);
    return 0;
}
