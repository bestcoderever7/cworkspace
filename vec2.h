#include <stdio.h>
#include <stdlib.h>

struct vec2{
    float x;
    float y;
    vec2() {

    }
    vec2(float z)
    {
        x = z;
        y = z;
    }
    vec2(float x, float y){
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
    bool equals(vec2 v){
        return this->x == v.x && this->y == v.y;
    }
};

int main2(int argc, char** argv){
    vec2 v(5, 6);
    vec2 u(10, 11);
    v.add(u);
    v.sub(u);
    v.mul(u);
    v.div(u);
    printf("%f\n", v.x);
    printf("%f\n", v.y);
    return 0;
}