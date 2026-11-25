#define MAP_SIZE 1000

typedef struct Node{
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[MAP_SIZE];
} MyHashMap;

// Since multiple Keys can produce same index, 
// We can maintain Linked list to handle collisions

MyHashMap* myHashMapCreate() {
    MyHashMap* map = malloc(sizeof(MyHashMap));
    if(map == NULL) return NULL;

    for(int i=0; i < MAP_SIZE; i++){
        map->buckets[i] = NULL;
    }

    return map;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = key % MAP_SIZE;

    Node* current = obj->buckets[index];
    while(current != NULL){
        if(current->key == key){
            current->value = value;
            return;
        }

        current = current->next;
    }

    Node* newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->value = value;
    newNode->next = obj->buckets[index];

    obj->buckets[index] = newNode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index = key % MAP_SIZE;

    Node* current = obj->buckets[index];

    while(current != NULL){
        if(current->key == key){
            return current->value;
        }

        current = current->next;
    }

    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = key % MAP_SIZE;

    Node* current = obj->buckets[index];
    Node* previous = NULL;

    while(current != NULL){
        if(current->key == key){
            if(previous == NULL){
                obj->buckets[index] = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for(int i=0; i < MAP_SIZE; i++){
        Node* current = obj->buckets[i];

        while(current != NULL){
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

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