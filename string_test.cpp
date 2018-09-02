#include "unit_test.h"

#include "string.h"

int main(int argc, char** argv){
    
    // #1
    String s1("taco");
    ASSERT(4 == s1.length());
    // #2
    ASSERT(s1.equals("taco"));
    // #3
    ASSERT(!s1.equals("burrito"));
    // #4
    String s2(s1);
    ASSERT(s2.equals("taco"));
    // #5
    ASSERT(s2.equals(s1));
    // #6
    s2.append("s and");
    ASSERT(s2.equals("tacos and"));
    // #7
    ASSERT(!s2.equals(""));
    // #8
    String s3(" burritos");
    s2.append(s3);
    ASSERT(s2.equals("tacos and burritos"));



    return 0;
}