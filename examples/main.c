
#include <stdio.h>
#include "map.h"




int main(){
    // TODO: find the size of hashmap function
    // find if hashmap is empty
    // write test for hashmap


    map_str_t hashmap;
    map_init(&hashmap);

    map_set(&hashmap, "testkey0", "testvalue");
    map_set(&hashmap, "testkey1", "testvalue");
    map_set(&hashmap, "testkey2", "testvalue");
    // map_set(&hashmap, "testkey3", "testvalue");
    // map_set(&hashmap, "testkey4", "testvalue");
    // map_set(&hashmap, "testkey5", "testvalue");
    // map_set(&hashmap, "testkey6", "testvalue");
    // map_set(&hashmap, "testkey7", "testvalue");
    // map_set(&hashmap, "testkey8", "testvalue");

    printf("size %d\n", map_size(&hashmap));

    // printf("nnodes: %d\n", hashmap.base.nnodes); // number of key, value
    // printf("nbuckets: %d\n", hashmap.base.nbuckets); // power of 2 buckets to hold nodes

    char** val = map_get(&hashmap, "testkey");
    if (val) {
        printf("value: %s\n", *val);
    } else {
        printf("value not found\n");
    }
}
