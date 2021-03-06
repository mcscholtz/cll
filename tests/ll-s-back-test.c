#include "suite.h"
#include "ll.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

void ll_s_back(CuTest * tc)
{
    const int LOOPS = 1000000;
    struct ll * list = ll_new(SINGLE);
    
    for(int i = 0; i < LOOPS; i++){
        struct ln * node = ll_new_node(&i,sizeof(i),SINGLE);
        
        list->push_back(list, node);
        
        //Get the value from the head of the list
        int * f = list->back(list);
        CuAssertIntEquals(tc, i, *f);
        
        //change the value of data pointed to & validated that it changed
        *f = -123;
        f = list->back(list);
        CuAssertIntEquals(tc, -123, *f);

        CuAssertIntEquals(tc, list->length, i+1);
    }

    ll_delete(list);
}


int main(void) { return execute(ll_s_back);}