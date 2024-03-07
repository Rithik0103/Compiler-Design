#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for input string
#define MAX_LENGTH 100

// Define grammar rules
#define NUM_RULES 3
char *grammar_rules[NUM_RULES] = {
    "S -> NP VP",
    "NP -> Det N",
    "VP -> V"
};

// Function to check if a string matches a rule
int matches_rule(char *rule, char *str) {
    return strncmp(rule, str, strlen(rule)) == 0;
}

// Function to check if the input string satisfies the grammar
int check_grammar(char *input_string) {
    // Tokenize input string
    char *token = strtok(input_string, " ");
    int matched_rule = 0;

    // Check each token against grammar rules
    while (token != NULL) {
        matched_rule = 0;
        for (int i = 0; i < NUM_RULES; i++) {
            if (matches_rule(grammar_rules[i], token)) {
                matched_rule = 1;
                break;
            }
        }
        if (!matched_rule) {
            return 0; // Input string does not satisfy the grammar
        }
        token = strtok(NULL, " ");
    }

    return 1; // Input string satisfies the grammar
}

int main() {
    char input_string[MAX_LENGTH];

    // Read input string from user
    printf("Enter a sentence: ");
    fgets(input_string, MAX_LENGTH, stdin);

    // Remove trailing newline character
    input_string[strcspn(input_string, "\n")] = 0;

    // Check if input string satisfies grammar
    if (check_grammar(input_string)) {
        printf("Input string satisfies the grammar.\n");
    } else {
        printf("Input string does not satisfy the grammar.\n");
    }

    return 0;
}
