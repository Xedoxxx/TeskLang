#include "tesk/lexer/token.h"
#include <stdlib.h>

token* token_new(char* value, token_t type) {
    token* tkn = malloc(sizeof(token));
    if(!tkn) {
        return NULL;
    }
    tkn->value = value;
    tkn->type = type;
    return tkn;
}