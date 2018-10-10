#include <stdlib.h>

int main(){
	int size = 10*1024*1024;
	while(1){
		char *a = malloc(size);
		for (int i = 0; i < size; i++){
			a[i] = 0;
		}
		sleep(1);
	}
}
