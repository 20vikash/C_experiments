#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *p = &a;
    int **c = &p;

    printf("%d\n", **c);

    return 0;
}
