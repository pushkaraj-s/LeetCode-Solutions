class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> ans(2);
        
        // Convert arrays into Hash sets
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        for(int val : set1){
            if(set2.find(val) == set2.end()){
                ans[0].push_back(val);
            }
        }

        for(int val : set2){
            if(set1.find(val) == set1.end()){
                ans[1].push_back(val);
            }
        }

        return ans;
    }
};