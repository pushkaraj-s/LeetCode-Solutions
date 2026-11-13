/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Approach: reduce checking element from target and try serching for other number in rest of the array
//if other number is found store their indices in returned array
// nums = array, nusSize = int, target = int, returnSize = array
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = NULL;
    
    ans = (int*)calloc(2,sizeof(int));
    *returnSize = 2;
    


    for(int i=0; i < numsSize; i++){
        int temp = target - nums[i];
        for(int j=i+1; j<numsSize; j++){
            if((temp == nums[j]) && (i != j)){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
            
        }
    }
    return ans;
}