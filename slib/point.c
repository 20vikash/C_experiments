#include <stdio.h>
#include "point.h"

void _hello(Point_t *p) {
    printf("%d\n", p->a);
    printf("%d\n", p->b);
}

void _init_point(Point_t *p, int a, int b) {
    p->a = a;
    p->b = b;
    p->hello = _hello;
}
