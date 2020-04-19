
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "map.h"



void test_with_many_values(int n);
void test_remove();
void test_replace();
void test_adding();
void test_allocation();
void test_isempty();

int main(){

    test_isempty();
    // test_allocation();
    // test_with_many_values(10);
    // test_remove();
    // test_replace();
    // test_adding();


}


void test_isempty(){
    map_int_t hashmap;
    map_init(&hashmap);

    if(map_isempty(&hashmap))
        printf("it's empty\n");
    else
        printf("it's NOT empty\n");

    printf("Adding a key\n");
    map_set(&hashmap, "somthing", 1);

    if(map_isempty(&hashmap))
        printf("it's empty\n");
    else
        printf("it's NOT empty\n");
}

void test_adding(){
    map_int_t hashmap;
    map_init(&hashmap);

    char* key1 = "Ea";
    char* key2 = "FB";

    map_set(&hashmap, key1, 1);
    printf("key1 is %d, AND SHOULD BE 1\n", *map_get(&hashmap, key1));

    map_set(&hashmap, key2, 2);
    printf("key2 is %d, AND SHOULD BE 2\n", *map_get(&hashmap, key2));

    map_deinit(&hashmap);
}


void test_replace(){

    map_int_t hashmap;
    map_init(&hashmap);

    char* key = "Hello";

    map_set(&hashmap, key, 1);
    printf("key is %d, AND SHOULD BE 1\n", *map_get(&hashmap, key));

    map_set(&hashmap, key, 2);
    printf("key is %d, AND SHOULD BE 2\n", *map_get(&hashmap, key));

    map_deinit(&hashmap);
}


void test_remove(){

    map_int_t hashmap;
    map_init(&hashmap);

    char* key1 = "Hello";
    char* key2 = "Goodbye";
    char* key3 = "new";

    map_set(&hashmap, key1, 1);
    printf("ADDING KEY1, SIZE IS %d AND SHOULD BE 1\n", map_size(&hashmap));

    map_set(&hashmap, key2, 2);
    printf("ADDING KEY2, SIZE IS %d AND SHOULD BE 2\n", map_size(&hashmap));

    map_remove(&hashmap, key1);
    printf("REMOVE KEY1, SIZE IS %d AND SHOULD BE 1\n", map_size(&hashmap));

    printf("key2: %d\n", *map_get(&hashmap, key2));

    map_remove(&hashmap, key2);
    printf("REMOVE KEY2, SIZE IS %d AND SHOULD BE 0\n", map_size(&hashmap));

    map_set(&hashmap, key3, 3);
    printf("ADDING KEY3, SIZE IS %d AND SHOULD BE 1\n", map_size(&hashmap));
    printf("key3: %d\n", *map_get(&hashmap, key3));

    map_deinit(&hashmap);
}



void test_with_many_values(int n){

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
                map_remove(&hashmap, buf);

            } else{
                printf("\033[0;31m");
                printf("wrong ->%s\n", *val);
                break;
            }

        } else {
            printf("value not found\n");
            printf("wrong ->%s\n", buf);
            break;
        }
    }

    printf("nbuckets: %d\n", hashmap.base.nbuckets); // power of 2 buckets to hold nodes
    printf("size %d\n", map_size(&hashmap));
    map_deinit(&hashmap);
}

void test_allocation(){
    map_int_t hashmap;
    map_init(&hashmap);

    char* key = "Ea";

    if((map_set(&hashmap, key, 1)) == -1)
        printf("ALLOCATION FAILD\n");
    else
        printf("key is %d, AND SHOULD BE 1\n", *map_get(&hashmap, key));
}
