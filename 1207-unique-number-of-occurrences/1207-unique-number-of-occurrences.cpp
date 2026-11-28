class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Convert array into unordered map
        // Store key, freq pairs in map
        // Check weather any freq is duplicate using set

        unordered_map<int, int> freq;
        
        // Count frequencies
        for(int num : arr){
            freq[num]++;
        }

        unordered_set<int> seen;
        
        // Check if frequiencies are unique
        for(auto iterator : freq){
            // "iterator" will be received as a pair (const int, int)
            // Access second element in this pair
            int count = iterator.second;

            // insert() will return pair as (iterator, bool)
            // To indicate of insertion passed or failed
            // Insertion will fail if element already exsists
            auto result = seen.insert(count);

            if(!result.second){
                return false;
            }
        }

        for(const auto& [val, count] : freq){
            cout << "Value: " << val << ", Frequency: " << count << endl;
        }

        return true;
    }
};