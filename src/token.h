#pragma once

#include <stddef.h>

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
} TokenKind;

typedef union {
    int number;
} TokenLiteral;

typedef struct {
  TokenKind kind;
  const char *lexeme;
  size_t len;
  TokenLiteral literal;
} Token;

void token_print(Token *t);
