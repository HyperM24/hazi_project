#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ervenyes_c(const char* input) {
    if (!*input) {
        return 0;
    }
    
    if (!isalpha(*input) && *input != '_') {
        return 0;
    }
    
    for (; *input; ++input) {
        if (!isalnum(*input) && *input != '_') {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char input[100];
    
    printf("Adj meg sztringeket '*' vegjelig!\n");
    
    while (1) {
        printf("\nInput: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;  
        }
        
        
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
        
        
        int empty = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isspace(input[i])) {
                empty = 0;
                break;
            }
        }

        if (strcmp(input, "*") == 0) {
            break;
        }
        
        
        if (ervenyes_c(input)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
