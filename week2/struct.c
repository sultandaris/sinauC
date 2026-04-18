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
    struct anjing jack = {'c', 'C', 20 };

    printf("%d %d" , sizeof(cimol) , sizeof(jack));
}
