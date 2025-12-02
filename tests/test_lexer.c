#include <tesk/lexer/lexer.h>
#include <tesk/lexer/token.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\033[34m Parse test:\n");
    char* teststr = "fn main() i32 {\n"
                    "    i32 var = 72; \n"
                    "    ret 0;\n"
                    "}";
    printf("%s\n", teststr);
    vec_t* tokens = lexer_tokenize(teststr);
    for(int i=0; i<vec_len(tokens); i++) {
        token* tkn = vec_get(tokens, i);
        printf("%s\n", token_tostr(tkn));
    }
    vec_free(tokens);
    printf("\033[0m");
}