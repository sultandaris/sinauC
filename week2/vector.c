#include <stdio.h>
#include <stdlib.h>

typedef struct vector vector;

struct vector
{
    int* current;
    int* min;
    int* max;
    int size; 
};

void vpop(struct vector *temp){
    if((char *)temp->max - (char *)temp->current == 1){
        char* val = (char*)(&temp->current); 
        (*val)-=3;
    }else if(temp->current == temp->min){
        printf("tidak ada yang bisa di pop, memori sudah kosong!\n");
    }else{
        (temp->current)--;
        printf("3\n");
    }

    char* target = (char*)temp->current; 
    int i;
    for (i = 0; i < 4; i++) {
        *target = 0; 
        target++;
    }
}

void process(vector *temp, int val){
    char* target = (char*)temp->current; 
    char* nilai = (char*)&val;
    int i = 0;
    for (i = 0; i < 4; i++) {
        *target = *nilai; 
        target++;
        nilai++;
    }
}

void vpush(struct vector *temp, int val){
    if(((temp->current)+1) > temp->max){
        printf("tidak bisa push lagi, memori akan di resize\n");
        vresize(temp);
        process(temp, val);
        return;
    }

   process(temp, val);

    if(((temp->current)+1) == temp->max){
        char* val = (char*)(&temp->current); 
        (*val)+=3;
    }else{
        ((temp->current))++;
    }
};

void vresize(vector *x){
    int *offset = (char *)x->current - (char *)x->min;
    int *baru = realloc(x->min, 2*(x->size) * sizeof(int));  
    
    printf("%d %d %d %d--- \n", x->current, x->max, x->min, offset);

    x->size *= 2;
    x->current = (int) x->min + (int) offset + 1;
    x->min = baru;
    x->max = x->min + x->size;

    printf("%d %d %d--- \n", x->current, x->max, x->min);
}

void show(struct vector val){
    int* i;
    for(i = val.min; i < val.max; i++){
        printf("%d ",*i);
    };        
    printf("\n");
}

int main(){
    vector v;

    /*initializing*/
    v.min = malloc(2 * sizeof(int));
    v.current = v.min;
    v.max = v.min + 2;
    v.size = 2;

    vpush(&v,10);
    vpush(&v,20);
    show(v);

    vpush(&v,50);
    vpush(&v,50);
    vpush(&v, 350);
    show(v);

    return 0;
}
