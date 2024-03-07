#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char ch;
    int char_count = 0, word_count = 0, line_count = 0;
    int in_word = 0; // Flag to indicate if currently inside a word

    printf("Enter text (press Ctrl+D to end):\n");

    // Read characters from standard input until EOF
    while ((ch = getchar()) != EOF) {
        // Increment character count for each character
        char_count++;

        // Increment word count if the character is not whitespace and not inside a word
        if (!isspace(ch) && !in_word) {
            in_word = 1;
            word_count++;
        }

        // If the character is a newline character, increment line count and reset word flag
        if (ch == '\n') {
            line_count++;
            in_word = 0;
        }

        // Reset word flag if the character is whitespace
        if (isspace(ch)) {
            in_word = 0;
        }
    }

    // Adjust line count if the last line does not end with a newline character
    if (char_count > 0 && ch != '\n') {
        line_count++;
    }

    printf("Number of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);

    return 0;
}
