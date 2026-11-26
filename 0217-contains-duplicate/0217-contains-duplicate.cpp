class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Let's try to do this using Hash map approach
        unordered_map<int, int> seen;
        for (int num : nums){
            if(seen[num] >= 1){
                return true;
            }
            seen[num]++;
        }
        return false;
    }
};