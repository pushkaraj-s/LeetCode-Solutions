int compare(const void* a, const void* b){
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;

    if(int_a > int_b) return 1;
    if (int_a < int_b) return -1;
    return 0;
}

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int half = numsSize/2;

    qsort(nums, numsSize, sizeof(int), compare);

    int temp = nums[0];

    for(int i=0; i < numsSize; i++){
        if(nums[i] == temp){
            count++;
            if(count > half){
                return temp;
            }   
        } 
        else {
            temp = nums[i];
            count = 1;
        }
    }

    return 0;
}