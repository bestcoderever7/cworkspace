#include "unit_test.h"

#include "vec2.h"

int main(int argc, char** argv){
    //TEST# 1
    vec2 v(0);
    ASSERT(v.x == 0 && v.y == 0);

    //TEST# 2
    vec2 v2(3, 5);
    ASSERT(v2.x == 3 && v2.y == 5);

    //TEST# 3
    vec2 v3(v2);
    ASSERT(v3.x == 3 && v3.y == 5);

    //TEST# 4
    v.add(v2);
    ASSERT(v.x == 3 && v.y == 5);

    //TEST# 5
    v.sub(v3);
    ASSERT(v.x == 0 && v.y == 0);

    //TEST# 6
    v2.mul(v3);
    ASSERT(v2.x == 9 && v2.y == 25);

    //TEST# 7
    v2.x++;
    v2.y++;
    ASSERT(v2.x == 10 && v2.y == 26);

    //TEST# 8
    v2.div(vec2(2, 2));
    ASSERT(v2.x == 5 && v2.y == 13);

    //TEST# 9
    vec2 v4(5, 13);
    ASSERT(v2.equals(v4));

    return 0;
}