#ifndef TOKEN_H
#define TOKEN_H

typedef enum token_t {
    MINUS,
    PLUS,
    STAR,
    SLASH,
    
    NUM,
    
    LPARENT,
    RPARENT,
    SEMICOLON,
    
    EOF
} token_t;

typedef struct token {
    char* value;
    token_t type;
} token;

token* token_new(char* value, token_t type);

#endif