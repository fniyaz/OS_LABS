#include <stdio.h>
#include <stdlib.h>

int main(){
    
}

void *my_realloc(void * ptr, int size){
    char* np = malloc(size);
    for(int i = 0; i < size; i++)
        np[i] = ((char*)ptr)[i];
    
    free(ptr);
    return (void*)np;
}
