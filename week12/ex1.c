#include <stdio.h>
#include <stdlib.h>
#define C 20


int main(){
    FILE *r = fopen("/dev/random", "r");
    FILE *w = fopen("ex1.txt", "w");
    
    char *buff = malloc(C*sizeof(char));
    
    fread(buff, sizeof(char), C, r);
    fwrite(buff, sizeof(char), C, w);
    
    fclose(r);
    fclose(w);
    
    return 0;
}
