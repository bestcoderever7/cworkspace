#include <stdio.h>
#include <stdlib.h>

struct vec2{
    int x;
    int y;
    vec2(int x, int y){
        this->x = x;
        this->y = y;
    }
    void add(vec2 v){
        this->x += v.x;
        this->y += v.y;
    } void sub(vec2 v){
        this->x -= v.x;
        this->y -= v.y;
    } void mul(vec2 v){
        this->x *= v.x;
        this->y *= v.y;
    } void div(vec2 v){
        this->x /= v.x;
        this->y /= v.y;
    }
};

int main(int argc, char** argv){
    vec2 v(5, 6);
    vec2 u(10, 11);
    v.add(u);
    v.sub(u);
    v.mul(u);
    v.div(u);
    printf("%i\n", v.x);
    printf("%i\n", v.y);
    return 0;
}