#include "tesk/parser/expr.h"
#include <stdlib.h>

expr_t* expr_new_num(double value) {
    expr_t* expr = malloc(sizeof(expr_t));
    expr->type = EXPR_NUMBER;
    expr->data.number.value = value;
    return expr;
}

expr_t* expr_new_var(const char* name) {
    expr_t* expr = malloc(sizeof(expr_t));
    expr->type = EXPR_VARIABLE;
    expr->data.variable.name = strdup(name);
    return expr;
}

expr_t* expr_new_bin(expr_t* left, operation_t op, expr_t* right) {
    expr_t* expr = malloc(sizeof(expr_t));
    expr->type = EXPR_BINARY;
    expr->data.binary.op = op;
    expr->data.binary.left = left;
    expr->data.binary.right = right;
    return expr;
}

/* Example usage: (x + 5) * 3
expr_t* example = create_binary(
    expr_new_bin(
        expr_new_var("x"), 
        ADD,
        expr_new_num(5)
    ),
    MUL,
    expr_new_num(3)
);
 */