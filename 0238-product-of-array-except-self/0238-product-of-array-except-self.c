/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // Lowest num.lenght is 2, We don't need to add (numsSize == 0) check
    // Space complexitiy = O(n)

    int* ans = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    
    ans[0] = 1;

    for(int i=1; i < numsSize; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;

    for(int i=numsSize -1; i >= 0; i--){
        ans[i] = ans[i] * suffix;
        suffix = suffix * nums[i];
    }

    return ans;
}