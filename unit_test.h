#pragma once

#include <iostream>
static unsigned int ctr = 0;
#define  ASSERT(X) \
printf("Running Test #%i... ", ++ctr); \
if(X) { \
    printf("PASSED\n"); \
}else{ \
    printf("FAILED\n"); \
    return 1;\
} 