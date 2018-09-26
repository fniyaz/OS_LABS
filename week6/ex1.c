#include <stdio.h>
#include <stdlib.h>


int main(){
	char *a, *b=malloc(13);
	a = "Hello, Pipe!";
	int p[2];
	pipe(p);
	write(p[1], a, 12);
	read(p[0], b, 12);
	printf(b);
	close(p[0]);
	close(p[1]);
}
