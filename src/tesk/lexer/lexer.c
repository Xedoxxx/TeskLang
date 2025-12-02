#include "tesk/lexer/lexer.h"
#include "tesk/lexer/token.h"
#include <vec.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <string_builder.h>

typedef struct lexer {
    size_t position;
    size_t length;
    vec_t* tokens;
    char * input;
} lexer;

token* lexer_tokenize_number(lexer* lxr) {
    size_t pos = lxr->position;
    str_t* buffer = str_new(16);
    char it = lxr->input[lxr->position];
    bool has_dot = false;
    while(lxr->position < lxr->length && (isdigit(it) || it == '.' || it == '_')) {
        if(it == '_') {
            lxr->position++;
            continue;
        }
        if(it == '.' && has_dot) {
            str_free(buffer);
            fprintf(stderr, "Failed in tokenize number in %ld (Number can't have second dot)", pos);
            return NULL;
        } else if(it == '.' && !has_dot) {
            has_dot = true;
        }
        str_push(buffer, it);
        lxr->position++;
        it = lxr->input[lxr->position];
    }
    char* result = str_bld(buffer);
    str_free(buffer);
    return token_new(result, NUM);
}

vec_t* lexer_tokenize(char* input) {
    char* in_cpy = malloc(strlen(input)+1);
    strcpy(in_cpy, input);
    lexer lxr = { 0, strlen(input), vec_new(sizeof(token)), in_cpy };
    while(lxr.position < lxr.length) {
        char it = lxr.input[lxr.position];
        if(isspace(it)) {
            lxr.position++;
            continue;
        }
        switch(it) {
            case '+': {
                vec_push(lxr.tokens, token_new("+", PLUS));
                lxr.position++;
                continue;
            }
            case '-': {
                vec_push(lxr.tokens, token_new("-", MINUS));
                lxr.position++;
                continue;
            }
            case '*': {
                vec_push(lxr.tokens, token_new("*", STAR));
                lxr.position++;
                continue;
            }
            case '/': {
                vec_push(lxr.tokens, token_new("/", SLASH));
                lxr.position++;
                continue;
            }
            case ':': {
                vec_push(lxr.tokens, token_new(":", SEMICOLON));
                lxr.position++;
                continue;
            }
            case '(': {
                vec_push(lxr.tokens, token_new("(", LPARENT));
                lxr.position++;
                continue;
            }
            case ')': {
                vec_push(lxr.tokens, token_new(")", RPARENT));
                lxr.position++;
                continue;
            }
        }
        if(isdigit(it)) {
            token* tkn = lexer_tokenize_number(&lxr);
            if(!tkn) {
                free(lxr.input);
                vec_free(lxr.tokens);
                break;
            }
            vec_push(lxr.tokens, tkn);
            continue;
        }
        fprintf(stderr, "Unknown symbol '%c' in %ld\n", it, lxr.position);
        free(lxr.input);
        vec_free(lxr.tokens);
        break;
    }
    return lxr.tokens;
}