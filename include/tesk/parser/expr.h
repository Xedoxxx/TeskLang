#ifndef EXPR_H
#define EXPR_H

typedef enum operation {
    ADD, // + //
    MUL, // * //
    SUB, // - //
    DIV, // / //
} operation_t;

typedef struct expr_t expr_t;

typedef enum {
    EXPR_BINARY, // +, -, *, /, etc. //
    EXPR_NUMBER, // 3.14 //
    EXPR_VARIABLE // my_var //
} expr_type_t;

typedef struct {
    operation_t op;
    expr_t* left;
    expr_t* right;
} binary_expr_t;

typedef struct {
    double value;
} number_expr_t;

typedef struct {
    char* name;
} variable_expr_t;

struct expr_t {
    expr_type_t type;
    union {
        binary_expr_t binary;
        number_expr_t number;
        variable_expr_t variable;
    } data;
};

expr_t* expr_new_num(double value);
expr_t* expr_new_var(const char* name);
expr_t* expr_new_bin(expr_t* left, operation_t op, expr_t* right);

#endif 