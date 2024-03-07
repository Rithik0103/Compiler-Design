#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char expression[100];
    char temp[3]; // Temporary variable name
    int temp_count = 0; // Counter for temporary variables

    // Read input expression from the user
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove trailing newline character
    expression[strcspn(expression, "\n")] = 0;

    // Tokenize the expression
    char *token = strtok(expression, "+-*/");

    // Print the initial assignment
    printf("t%d = %s\n", temp_count, token);

    // Iterate through the expression
    while (token != NULL) {
        char op = expression[strlen(token)]; // Get the operator
        token = strtok(NULL, "+-*/");
        
        // If there is no more token, break the loop
        if (token == NULL) break;

        // Generate temporary variable name
        sprintf(temp, "t%d", ++temp_count);

        // Print the operation in three-address code
        printf("%c %s %s => %s\n", op, token, temp, temp);
    }

    return 0;
}
