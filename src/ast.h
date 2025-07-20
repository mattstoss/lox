#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "token.h"

typedef struct ASTNode ASTNode; // forward declaration

typedef struct {
  Token *op;
  ASTNode *left;
  ASTNode *right;
} ASTBinary;

typedef struct {
  Token *value;
} ASTLiteral;

typedef enum {
  AST_BINARY,
  AST_LITERAL,
} ASTNodeKind;

typedef struct ASTNode {
  ASTNodeKind kind;

  union {
    ASTBinary binary;
    ASTLiteral literal;
  } as;
} ASTNode;

ASTNode *ast_make_literal(Token *value);
ASTNode *ast_make_binary(Token *op, ASTNode *left, ASTNode *right);

void ast_print(ASTNode *node);
