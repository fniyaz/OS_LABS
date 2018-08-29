#include <stdio.h>

int main(int ac, char **args){
	int n;
	sscanf(args[1], "%d", &n);

	for (int i = 0; i < n; i++){
		for(int k = n-1; k > 0; k--){
			if (k <= i)
				printf("*");
			else
				printf(" ");
		}
		printf("*");
		for(int k = 1; k < n; k++){
			if (k <= i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");

	}

	return 0;
}
