#include <stddef.h>

#include "token.h"

// FIXME: change return type to int and add real error handling
size_t scan(const char *s, size_t len, Token *out, size_t max_tokens);
