#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char ** args){
    char* a_mode = "w";
    
    if (args[1][0] == '-'){
        if (strcmp(args[1], "-a") == 0){
            a_mode = "a";
        }
    }
    
    FILE *w = fopen(args[argc-1], a_mode);
    
    while(1){
        int c = getchar();
        if (feof(stdin))
            break;
        putchar(c);
        putc(c, w);
    }
    
    fclose(w);
    
    return 0;
}
