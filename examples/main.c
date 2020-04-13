
#include <stdio.h>
#include "map.h"




int main(){


    map_str_t hashmap;
    map_init(&hashmap);

    map_set(&hashmap, "testkey", "testvalue");

    char** val = map_get(&hashmap, "testkey");
    if (val) {
        printf("value: %s\n", *val);
    } else {
        printf("value not found\n");
    }
}
