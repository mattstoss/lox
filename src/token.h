#include <stddef.h>

typedef enum {
    TOKEN_PLUS,
} TokenKind;

typedef struct {
  TokenKind kind;
  const char *lexeme;
  size_t len;
} Token;
