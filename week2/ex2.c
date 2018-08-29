#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char *str = malloc(64);
	scanf("%s", str);
	int len = strlen(str);
	char *str2 = malloc(len);

	for(int i = 0; i < len; i++){
		str2[len-i-1] = str[i];
	}

	printf("%s", str2);


	return 0;
}
