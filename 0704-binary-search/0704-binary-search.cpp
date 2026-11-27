class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Let's take 2 pointers
        int st = 0;
        int end = nums.size() - 1;
        int mid = (st + end) / 2;

        while(st <= end){
            if(target < nums[mid]){
                end = mid - 1;
                mid = (st + end) / 2;
            } else if (target > nums[mid]){
                st = mid + 1;
                mid = (st + end) / 2;
            } else if (target == nums[mid]){
                return mid;
            }
        }

        return -1;
    }
};