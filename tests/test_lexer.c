#include <tesk/lexer/lexer.h>
#include <tesk/lexer/token.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define TEST_CODE \
"fn main() i32 {\n"\
"    var: i32 = 72;\n"\
"    ret 0;\n"\
"}"

int main() {
    printf("\033[34m Parse test:\n");
    
    char* code = TEST_CODE;
    
    printf("Code:\n%s\n", code);
    
    vec_t* tokens = lexer_tokenize(code);
    if (tokens == NULL) {
        fprintf(stderr, "Failed to tokenize\n");
    } else {
        for (int i = 0; i < vec_len(tokens); i++) {
            token* tkn = vec_get(tokens, i);
            printf("%s\n", token_tostr(tkn));
        }
        vec_free(tokens);
    }
    printf("\033[0m");
    
    return 0;
}