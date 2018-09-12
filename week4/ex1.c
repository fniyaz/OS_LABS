#include <unistd.h>
#include <stdio.h>

int main(){
    int n;
    if( fork() == 0)
        printf("Hello from child [%d - %d]\n", getpid(), n);
    else
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    
    return 0;
}
