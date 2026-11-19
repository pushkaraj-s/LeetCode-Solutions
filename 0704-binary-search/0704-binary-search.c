int search(int* nums, int numsSize, int target) {
    // Binary Search
    int st = 0, end = numsSize - 1;

    while(st <= end){
        int mid = (st + end)/2;

        if(target > nums[mid]){
            st = mid + 1;
        } else if (target < nums[mid]){
            end = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}