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

    //TEST# 10
    vec2 v5(10, 10);
    vec2 v6(0, 0);
    v6 = v5;
    ASSERT(v6.equals(v5));

    //TEST# 11
    ASSERT(v6 != v4);

    //TEST# 12
    vec2 v7 = v6 + v5;
    vec2 v8(20, 20);
    ASSERT(v7 == v8);

    //Test# 13
    vec2 v9(0, 0);
    ASSERT(v9 == v6 - v5);

    //Test# 14
    v9 = vec2(100, 100);
    ASSERT(v9 == v6 * v5);

    //Test# 15
    v9 = vec2(1, 1);
    ASSERT(v9 == v6 / v5);

    //Test #16
    v9 += v6;
    v5 = vec2(11, 11);
    ASSERT(v5 == v9);

    //Test #17
    v = vec2(5, 5);
    v -= vec2(2, 4);
    ASSERT(v == vec2(3, 1));

    //Test #18
    v = vec2(5, 5);
    v *= vec2(2, 4);
    ASSERT(v == vec2(10, 20));

    //Test #19
    v = vec2(8, 6);
    v /= vec2(2, 3);
    ASSERT(v == vec2(4, 2));

    return 0;
}