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
        for (size_t i = 0; i < token_count; i++) {
            Token *t = &tokens[i];
            printf("Token { kind: %d lexeme: %.*s }\n", t->kind, (int)t->len, t->lexeme);
        }
    }

    return 0;
}
