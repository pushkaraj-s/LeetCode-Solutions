void rotate(int* nums, int numsSize, int k) {
    // K is non negative
    // Create new array paste (numsSize - 1 - k) to numsSize elements at start
    // Place remaining elements after that
    if(k > numsSize){
        k = k % numsSize;
    } else if(k == numsSize){
        return;
    }

    int* temp = malloc(sizeof(int)*numsSize);
    int idx = 0;

    for(int i=numsSize-k; i < numsSize; i++){
        temp[idx++] = nums[i];
    }

    for(int i=0; i < numsSize-k; i++){
        temp[idx++] = nums[i];
    }

    for(int i=0; i < numsSize; i++){
        nums[i] = temp[i];
    }
}