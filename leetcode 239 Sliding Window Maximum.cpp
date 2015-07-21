// leetcode 239 Sliding Window Maximum.cpp

// This is NOT the optimal solution, time complexity is O[n log(k)].

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int i, size = nums.size();        
        vector<int> result;
        map<int, int> m;

        for (i = 0; i < k; i++) {
            m[nums[i]]++;
        }

        for (; i < size; i++) {
            result.push_back(m.rbegin()->first);
            m[nums[i - k]]--;
            if (!m[nums[i - k]]) m.erase(nums[i - k]);
            m[nums[i]]++;
        }

        if (size) result.push_back(m.rbegin()->first);

        return result;
    }
};
