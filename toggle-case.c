#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

        printf("%s\n", temp_word); // Menampilkan output ke stdout
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char word[100];
    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = 0; // Menghapus newline
        generate_toggle_case(word); // Menghasilkan kombinasi toggle case
    }

    fclose(file);
    return 0;
}
