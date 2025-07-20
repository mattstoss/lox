#include "ast.h"

ASTNode *ast_make_literal(Token *value) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->kind = AST_LITERAL;
  node->as.literal.value = value;
  return node;
}

ASTNode *ast_make_binary(Token *op, ASTNode *left, ASTNode *right) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->kind = AST_BINARY;
  node->as.binary.op = op;
  node->as.binary.left = left;
  node->as.binary.right = right;
  return node;
}

static void print_indent(int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
}

static void ast_print_indent(ASTNode *node, int indent) {
  if (!node) {
    return;
  }

  switch (node->kind) {
  case AST_LITERAL: {
    Token *val = node->as.literal.value;
    print_indent(indent);
    printf("%.*s\n", (int)val->len, val->lexeme);
    return;
  }

  case AST_BINARY: {
    Token *op = node->as.binary.op;
    print_indent(indent);
    printf("%.*s\n", (int)op->len, op->lexeme);
    ast_print_indent(node->as.binary.left, indent + 1);
    ast_print_indent(node->as.binary.right, indent + 1);
    return;
  }

  default:
    printf("ast_print: unknown kind %d", node->kind);
  }
}

void ast_print(ASTNode *node) {
    ast_print_indent(node, 0);
}
