#include "tesk/lexer/token.h"
#include <stdlib.h>
#include <string.h>

token* token_new(char* value, token_t type) {
    token* tkn = malloc(sizeof(token));
    if(!tkn) {
        return NULL;
    }
    tkn->value = value;
    tkn->type = type;
    return tkn;
}

const char* token_type_tostr(token_t token) {
    switch(token) {
        case MINUS:     return "MINUS";
        case PLUS:      return "PLUS";
        case STAR:      return "STAR";
        case SLASH:     return "SLASH";
        case NUM:       return "NUM";
        case DT:        return "DT";
        case ID:        return "ID";
        case KEYWORD:   return "KEYWORD";
        case LPARENT:   return "LPARENT";
        case RPARENT:   return "RPARENT";
        case LBRACE:    return "LBRACE";
        case RBRACE:    return "RBRACE";
        case COLON:     return "COLON";
        case SEMICOLON: return "SEMICOLON";
        case ASSIGN:    return "ASSIGN";
        case EOF_TOKEN: return "EOF (\\0)";
        default:        return "UNKNOWN_TOKEN";
    }
}

char* token_tostr(token *tkn) {
    char* value = tkn->value;
    char* type = token_type_tostr(tkn->type);
    size_t len = strlen(value) + strlen(type)+3;
    char* buffer = malloc(len);
    strcat(buffer, type);
    strcat(buffer, ": ");
    strcat(buffer, value);
    return buffer;
}