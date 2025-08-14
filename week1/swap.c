#include <stdio.h>

void swap(int *a, int *b){
	int x;
	x = *a;
	*a = *b;
	*b = x;
};

int main(){
	int a = 1;
	int b = 10;
	swap(&a,&b);
	printf("%d\t%d",a,b);
};
