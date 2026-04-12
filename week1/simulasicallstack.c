#include <stdio.h>
#include <stdlib.h>

void push(int val, int* nunjuk) {
    char* target = (char*)nunjuk; 
    char* nilai = (char*)&val;

    for (int i = 0; i < 4; i++) {
        *target = *nilai; 
        target++;
        nilai++;
    }

    (*nunjuk)++;
}

int main() {
    int* awal = (int*)malloc(2 * sizeof(int));
    int* nunjuk = awal;
    int* akhir = nunjuk + 2; 

    printf("Alamat: %d\n", (void*)nunjuk);
    push(4, nunjuk);
    printf("Alamat: %d\n", (void*)nunjuk);

    free(nunjuk); // Jangan lupa di-free ya
    return 0;
}