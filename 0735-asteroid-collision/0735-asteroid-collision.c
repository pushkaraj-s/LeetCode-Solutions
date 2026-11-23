/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void push(int* stack, int* top, int data);
void pop(int* top);


int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    // Base login: move all +ve asteroids in stack
    // Start comparing top of stack with current -ve asteroid
    // Find which one is smaller by comparing abs() value
    // Destroy them as needed
    // return reaming array
    int* stack = malloc(asteroidsSize*sizeof(int));
    int top = -1;

    for(int i=0; i < asteroidsSize; i++){
        int asteroid = asteroids[i];
        int alive = 1;

        while(alive && top >= 0 &&
              stack[top] > 0 && asteroid < 0){
            if(stack[top] < abs(asteroid)){
                    //Top asteroid exploes
                pop(&top);
            } else if (stack[top] == abs(asteroid)){
                //Both explode
                pop(&top);
                alive = 0;
            } else {
                //Current asteroid explodes
                alive = 0;
            }
        }

        if(alive){
            push(stack, &top, asteroid);
        }
    }
    
    *returnSize = top+1;

    return stack;
}

void push(int* stack, int* top, int data) {
    (*top)++;
    stack[*top] = data;
}

void pop(int* top) {
    (*top)--;
}

