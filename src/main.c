#include <stdio.h>
#include <string.h>

#include "ast.h"
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

        // FIXME: check if MAX_INPUT_LEN was too small and we didn't consume all input 

        Token tokens[MAX_TOKEN];
        size_t token_count = scan(input, strlen(input), tokens, MAX_TOKEN);
        for (size_t i = 0; i < token_count; i++) {
            Token *t = &tokens[i];
            printf("Token { kind: %d lexeme: %.*s }\n", t->kind, (int)t->len, t->lexeme);
        }

        // FIXME: implemet an actual parser
        ASTNode* left = ast_make_literal(&tokens[0]);
        ASTNode* middle = ast_make_literal(&tokens[2]);
        ASTNode* right = ast_make_literal(&tokens[4]);
        ASTNode* child = ast_make_binary(&tokens[1], left, middle);
        ASTNode* root = ast_make_binary(&tokens[3], child, right);

        ast_print(root);
    }

    return 0;
}
