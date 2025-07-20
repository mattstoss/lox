#include <stdio.h>
#include <string.h>

#include "scanner.h"

#define MAX_INPUT_LEN 100
#define MAX_TOKEN 10

int main(void) {
    char input[MAX_INPUT_LEN];

    while (1) {
        printf("> ");
        if (!fgets(input, sizeof(input), stdin)) {
            return 0;
        }

        Token tokens[MAX_TOKEN];
        size_t token_count = scan(input, strlen(input), tokens, MAX_TOKEN);
        printf("token_count: %zu\n", token_count);
    }

    return 0;
}
