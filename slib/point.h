typedef struct Point
{
    int a;
    int b;

    void (*hello)(struct Point*);
} Point_t;

void _hello(Point_t *p);
void _init_point(Point_t *p, int a, int b);
