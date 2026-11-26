class Solution {
private:
    struct Comparator{
        bool operator() (pair<char, int> &a, pair<char, int> &b){
            return a.second < b.second;
        }
    };
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        // This code is inspired from a Youtube video
        // Try to attempt this question on your own in future
        // Calculate freq of each task
        for (auto &task : tasks){
            freq[task]++;
        }

        // We will use max heap to get most freq task at the top
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comparator> maxHeap;
        for (auto &kv : freq){
            maxHeap.push({kv.first, kv.second});
        }

        // Task, freq, remaining, interval ready
        queue<tuple<char, int, int>> q;

        int intervals = 0;
        while(!maxHeap.empty() || !q.empty()){
            // Put tasks finished with cooldown back in hrap
            if(!q.empty()){
                auto [task, remaining, interval] = q.front();
                if(interval == intervals){
                    maxHeap.push({ task, remaining });
                    q.pop();
                }
            }

            if (maxHeap.empty()) { 
                intervals++; 
                continue;
            }

            // Do the next Task
            auto [task, remaining] = maxHeap.top();
            maxHeap.pop();
            remaining--;

            if(remaining > 0 && n > 0){
                q.push(make_tuple(task, remaining, intervals + n + 1));
            } else if (remaining > 0){
                maxHeap.push({task, remaining});
            }

            intervals++;
        }

        return intervals;
    }
};