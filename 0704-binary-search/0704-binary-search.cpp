class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Let's take 2 pointers
        int st = 0;
        int end = nums.size() - 1;


        while(st <= end){
            // Optimized mid calculation to avoid int overflow
            int mid = st + (end - st) / 2;

            if(target < nums[mid]){
                end = mid - 1;
            } else if (target > nums[mid]){
                st = mid + 1;
            } else if (target == nums[mid]){
                return mid;
            }
        }

        return -1;
    }
};