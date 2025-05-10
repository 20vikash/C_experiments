#include <stdio.h>

typedef struct Point
{
    int a;
    int b;

    void (*hello)(struct Point*);
} Point;

void _hello(Point *p) {
    printf("%d\n", p->a);
    printf("%d\n", p->b);
}

void _init_point(Point *p, int a, int b) {
    p->a = a;
    p->b = b;
    p->hello = _hello;
}

int main(int argc, char const *argv[])
{
    Point o;

    _init_point(&o, 1, 2);
    o.hello(&o);

    return 0;
}
