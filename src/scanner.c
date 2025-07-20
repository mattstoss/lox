#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "scanner.h"

static int is_numeric(char c) {
    return c >= '0' && c <= '9';
}

size_t scan(const char *s, size_t len, Token *out, size_t max_tokens) {
    size_t current = 0;
    size_t token_count = 0;

    while (current < len) {
        if (token_count >= max_tokens) {
            printf("scanner: token overflow\n");
            break;
        }

        char c = s[current];
        if (is_numeric(c)) {
            size_t start = current;
            while (current < len && is_numeric(s[current])) {
                current++;
            }

            size_t num_len = current - start;

            char tmp[32];
            if (num_len >= sizeof(tmp) - 1) {
                printf("scanner: numeric literal too long\n");
                break;
            }

            memcpy(tmp, &s[start], num_len);
            tmp[num_len] = '\0';

            int number = atoi(tmp);

            out[token_count++] = (Token){
                .kind = TOKEN_NUMBER, 
                .lexeme = s + start, 
                .len = num_len,
                .literal.number = number,
            };
        } else if (c == '+') {
            out[token_count++] = (Token){ 
                .kind = TOKEN_PLUS, 
                .lexeme = s + current, 
                .len = 1,
            };
            current++;
        } else if (c == '\n') {
            current++;
        } else if (c == ' ') {
            current++;
        } else {
            printf("scanner: unrecognized char '%c'\n", c);
            break;
        }
    }

    return token_count;
}
