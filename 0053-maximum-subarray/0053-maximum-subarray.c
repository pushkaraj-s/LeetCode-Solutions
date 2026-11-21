int maxSubArray(int* nums, int numsSize) {
    // Brute force Approach: Calculate sum for each subarray
    // Optimized approach: We can solve this using Kadane's Algorithm
    // The algorithm iterates through the array, adding elements to a current sum and resetting it to zero whenever it drops below zero.

    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i=0; i < numsSize; i++){
        currSum = currSum + nums[i];
        if(currSum > maxSum){
            maxSum = currSum;
        }
        
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}