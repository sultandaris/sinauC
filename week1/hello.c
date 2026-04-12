#include <stdio.h>

int main(){
	int a = 10;
	int* p = &a;
	*p = 90;
	printf("Alamat: %d\n", (void*)*p);
	return 0;
};
