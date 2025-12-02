#include <tesk/lexer/lexer.h>
#include <tesk/lexer/token.h>
#include <stdio.h>
int main() {
    vec_t* tokens = lexer_tokenize("(2+ 2) -  87 *22");
    for(int i=0; i<vec_len(tokens); i++) {
        token* tkn = vec_get(tokens, i);
        printf("%s\n", tkn->value);
    }
}