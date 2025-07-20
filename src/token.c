#include "token.h"

#include <stdio.h>

void token_print(Token *t) {
    printf("%.*s\n", (int)t->len, t->lexeme);
}
