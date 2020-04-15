
#include <stdio.h>
#include "map.h"




int main(){

    char* keys[] = {"testkey0", "testkey1", "testkey2", 
                    "testkey3", "testkey4", "testkey5", 
                    "testkey6", "testkey7", "testkey8", 
                    '\0'};

    size_t n = sizeof(keys)/sizeof(keys[0]) - 1;

    map_str_t hashmap;
    map_init(&hashmap);

    for(int i =0; i < n; i++){
        map_set(&hashmap, keys[i], keys[i]);
    }

    printf("size %d\n", map_size(&hashmap));
    // printf("nnodes: %d\n", hashmap.base.nnodes); // number of key, value
    // printf("nbuckets: %d\n", hashmap.base.nbuckets); // power of 2 buckets to hold nodes

    for(int i =0; i < n; i++){
        char** val = map_get(&hashmap, keys[i]);
        if (val) {
            printf("value: %s\n", *val);
        } else {
            printf("value not found\n");
        }
    }
}
