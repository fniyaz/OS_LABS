#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	
	printf("%ld %d\n", sizeof(i), i);
	printf("%ld %f\n", sizeof(f), f);
	printf("%ld %lf\n", sizeof(d), d);
}
