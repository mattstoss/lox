#include <stdio.h>

#include "scanner.h"

size_t scan(const char *s, size_t len, Token *out, size_t max_tokens) {
    size_t current = 0;
    size_t token_count = 0;

    while (current < len) {
        if (token_count >= max_tokens) {
            printf("scanner: token overflow");
            break;
        }

        char ch = s[current++];
        if (ch == '+') {
            out[token_count++] = (Token){ TOKEN_PLUS, NULL, 0 };
        } else if (ch == '\n') {
            continue;
        } else if (ch == ' ') {
            continue;
        } else {
            printf("scanner: unrecognized char '%c'\n", ch);
            break;
        }
    }

    return token_count;
}
