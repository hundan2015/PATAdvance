#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int a;
} Shit;

int main()
{
    Shit* a = (Shit*)malloc(sizeof(Shit));
    a->a = 1;
    printf("%d\n", a->a);

    printf("%10.3f\n",1.333333333);
    printf("%-10.3f\n",1.333333333);
    printf("%3.2s\n","123456");
    printf("%3.4s\n","123456");
    printf("%-3.5s%3.4s","123456","235678");
}