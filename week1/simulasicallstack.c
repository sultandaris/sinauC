#include <stdio.h>
#include <stdlib.h>

void push(int val, int** src) {
    char* target = (char*)*src; 
    char* nilai = (char*)&val;

    for (int i = 0; i < 4; i++) {
        *target = *nilai; 
        target++;
        nilai++;
    }

    (*src)++;
}

int main() {
    int* awal = (int*)malloc(2 * sizeof(int));
    int* nunjuk = awal;
    int* akhir = nunjuk + 2; 

    printf("Alamat: %d\n", (void*)nunjuk);
    push(400, &nunjuk);
    printf("Alamat: %d\n", (void*)nunjuk);

    return 0;
}