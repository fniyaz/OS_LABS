#include <stdio.h>
#include <stdlib.h>

int main(){
	char *a, *b=malloc(13);
	a = "Hello, Pipe!";
	int p[2];
	pipe(p);
	if (fork() == 0){
		read(p[0], b, 12);
		printf(b);
	}else{
		write(p[1], a, 12);
	}
}
