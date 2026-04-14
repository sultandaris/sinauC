#include <stdio.h>
#include <stdlib.h>

void pop(int** src, int* akhir, int* awal){

    if((char *)akhir - (char *)*src == 1){
        char** val = (char*)src; 
        (*val)-=3;
    }else if(*src == awal){
        printf("tidak ada yang bisa di pop, memori sudah kosong!\n");
    }else{
        (*src)--;
    }

    char* target = (char*)*src; 

    for (int i = 0; i < 4; i++) {
        *target = 0; 
        target++;
    }
}

void push(int val, int** src, int* akhir) {
    if((*src+1) > akhir){
        printf("tidak bisa push lagi, memori penuh\n");
        return;
    }
    char* target = (char*)*src; 
    char* nilai = (char*)&val;

    for (int i = 0; i < 4; i++) {
        *target = *nilai; 
        target++;
        nilai++;
    }

    if((*src+1) == akhir){
        char** val = (char*)src; 
        (*val)+=3;
    }else{
        (*src)++;
    }
}

void show(int* awal, int* akhir){
    for(int* i=awal; i<akhir; i++){
        printf("%d ",*i);
    };        
    printf("\n");
}

int main() {
    int* awal = (int*)malloc(2 * sizeof(int));
    int* nunjuk = awal;
    int* akhir = nunjuk+2; 

    printf("awal: %d akhir:%d \n", awal, akhir);

    push(400,&nunjuk,akhir);
    printf("current : %d \n", nunjuk);
    show(awal, akhir);

    push(900,&nunjuk,akhir);
    printf("current : %d \n", nunjuk);
    show(awal, akhir);

    push(9000,&nunjuk,akhir);
    printf("current : %d \n", nunjuk);
    show(awal, akhir);

    pop(&nunjuk,akhir,awal);
    printf("current : %d \n", nunjuk);
    show(awal, akhir);

    pop(&nunjuk,akhir,awal);
    printf("current : %d \n", nunjuk);
    show(awal, akhir);


    pop(&nunjuk,akhir,awal);
    printf("current : %d \n", nunjuk);
    show(awal, akhir);


    return 0;
}