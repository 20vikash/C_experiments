#include "point.h"

int main(int argc, char const *argv[])
{
    Point_t o;

    _init_point(&o, 1, 2);
    o.hello(&o);

    return 0;
}
