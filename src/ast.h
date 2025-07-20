#include <stdlib.h>

#include "token.h"

typedef struct ASTNode ASTNode; // forward declaration

typedef struct {
  TokenKind op;
  ASTNode *left;
  ASTNode *right;
} ASTBinary;

typedef struct {
  TokenLiteral value;
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

ASTNode *ast_make_literal(TokenLiteral value) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->kind = AST_LITERAL;
  node->as.literal.value = value;
  return node;
}

ASTNode *ast_make_binary(TokenKind op, ASTNode *left, ASTNode *right) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->kind = AST_BINARY;
  node->as.binary.op = op;
  node->as.binary.left = left;
  node->as.binary.right = right;
  return node;
}