#ifndef TOKEN_H
#define TOKEN_H

/*
    Data types:
    i8, i16, i32, i64
    u8, u16, u32, u64
    f8, f16, f32, f64
    bool, char (1 byte)
 */

typedef enum token_t {
    MINUS, // -
    PLUS,  // +
    STAR,  // *
    SLASH, // /
    
    NUM,   // int, float, etc.
    
    DT, // data type
    ID, // identifier
    KEYWORD, // fn, if, else, etc.
    
    LPARENT,   // (
    RPARENT,   // )
    LBRACE,    // {
    RBRACE,    // }
    COLON,     // :
    SEMICOLON, // ;
    ASSIGN,    // =
    
    EOF_TOKEN  // \0
} token_t;

typedef struct token {
    char* value;
    token_t type;
} token;

token* token_new(char* value, token_t type);

char* token_tostr(token *tkn);

#endif