#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Brute force approach: Check every element of nums1 with nums2, vice versa

        vector<vector<int>> ans(2);
        bool found = false;

        // Check elements of nums1 against nums2
        for(int val1 : nums1){
            found = false;
            for(int val2 : nums2){
                if(val1 == val2){
                    found = true;
                    break;
                }
            }

            // Check for duplicates in ans[0]
            bool alreadyAdded= false;
            for(int x : ans[0]){
                if(x == val1){
                    alreadyAdded = true;
                    break;
                }
            }

            if(!found && !alreadyAdded){
                ans[0].push_back(val1);
            }
        }

        // Check elements of nums2 against nums1
        for(int val2 : nums2){
            found = false;
            for(int val1 : nums1){
                if(val1 == val2){
                    found = true;
                    break;
                }
            }

            // Check for duplicates in ans[1]
            bool alreadyAdded= false;
            for(int x : ans[1]){
                if(x == val2){
                    alreadyAdded = true;
                    break;
                }
            }

            if(!found && !alreadyAdded){
                ans[1].push_back(val2);
            }
        }

        return ans;
    }
};