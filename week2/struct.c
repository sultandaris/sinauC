#include <stdio.h>

struct kucing
{
    int umur;
    char ras;
    char f;
};

struct anjing
{
    char ras;
    int k;
    char umur;
};

int main(){
    struct kucing cimol = { 10, 'X' , 'd' };
    struct anjing jack = {'c', 20 , 'f' };

    printf("%d %d" , sizeof(cimol) , sizeof(jack));
}
