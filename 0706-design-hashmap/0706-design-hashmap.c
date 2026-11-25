#define MAP_SIZE 1000001

// Basic implementation of HashMap using static Array

typedef struct {
    int map[MAP_SIZE];
    
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* obj = malloc(sizeof(MyHashMap));
    if(obj == NULL){
        return NULL;
    }

    for(int i=0; i < MAP_SIZE; i++){
        obj->map[i] = -1;
    }

    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->map[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->map[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->map[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/