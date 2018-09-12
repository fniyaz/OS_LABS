#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char* str = malloc(100);
	while(1){
		scanf("%s", str);
		system(str);
	}

	free(str);
	return 0;
}
