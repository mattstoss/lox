#include <stddef.h>

#include "token.h"

size_t scan(const char *s, size_t len, Token *out, size_t max_tokens);
