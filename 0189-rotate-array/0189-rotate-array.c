void rotate(int* nums, int numsSize, int k) {
    // Let's see how can we solve this using 2 pointer approach
    // This question can be solved in O(1) space, by reversing the array
    
    if(k > numsSize){
        k = k % numsSize;
    } else if (k == numsSize){
        return;
    }

    int p1 = 0;
    int p2 = numsSize - 1;

    while(p1 < p2){
        int temp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = temp;
        p1++;
        p2--;
    }

    p1 = 0;
    p2 = k - 1;
    while(p1 < p2){
        int temp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = temp;
        p1++;
        p2--;
    }

    p1 = k;
    p2 = numsSize - 1;
    while(p1 < p2){
        int temp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = temp;
        p1++;
        p2--;
    }

}