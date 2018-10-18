#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned int BITS;

typedef struct page_frame{
    BITS used;
    int page;
} PG;

int main(int c, char ** args){
    int ADDER = UINT_MAX - (UINT_MAX >> 1);
    
    int n;
    sscanf(args[1], "%d", &n);
    FILE * fd = fopen("input.txt", "r");
    
    PG **pages = malloc(n*sizeof(PG*));
    for(int j=0; j<n; j++){
        pages[j] = malloc(sizeof(PG));
        pages[j]->used=0;
        pages[j]->page=-1;
    }

    int miss = 0;
    for (int i = 0; i < 1000; i++){
        for(int j=0; j<n; j++)
            pages[j]->used = (pages[j]->used >> 1);
        int pn;
        int av = 0;
        fscanf(fd, "%d", &pn);
        for(int j=0; j<n; j++)
            if (pages[j]->page == pn){
                av = 1;
                pages[j]->used = ADDER | pages[j]->used;
            }
        
        if (av==0){
            miss++;
            int last = 0;
            BITS min = pages[0]->used;
            for(int j = 1; j < n; j++)
                if (pages[j]->used < min){
                    min = pages[j]->used;
                    last = j;
                }
            pages[last]->used = ADDER;
            pages[last]->page = pn;
        }
    }
    printf("%d/1000", miss);
}
