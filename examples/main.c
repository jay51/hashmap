
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "map.h"




int main(){

    int n = 10000;

    map_str_t hashmap;
    map_init(&hashmap);

    for(int i =0; i < n; i++){
        char buf[245];
        char* key_val = "testkey_val";
        sprintf(buf, "%s%d", key_val, i);
        // printf(buf);
        map_set(&hashmap, buf, buf);
    }

    printf("size %d\n", map_size(&hashmap));
    // printf("nnodes: %d\n", hashmap.base.nnodes); // number of key, value
    // printf("nbuckets: %d\n", hashmap.base.nbuckets); // power of 2 buckets to hold nodes

    for(int i =0; i < n; i++){
        sleep(0.9);
        char buf[245];
        char* key_val = "testkey_val";
        sprintf(buf, "%s%d", key_val, i);
        char** val = map_get(&hashmap, buf);

        if (val) {
            if((strcmp(buf, *val)) == 0){
                printf("\033[0m");
                printf("correct -> %s\n", *val);

            } else{
                printf("\033[0;31m");
                printf("wrong ->%s\n", *val);
            }

        } else {
            printf("value not found\n");
        }
    }
}
