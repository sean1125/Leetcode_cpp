// leetcode 239 Sliding Window Maximum.cpp

// This is the optimal solution, the time complexity is O(n).

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int i, size= nums.size();
        vector<int> result;
        deque<int> q;

        for (i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
        }

        for (; i < size; i++) {
            result.push_back(nums[q.front()]);

            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);

            while (q.front() <= i - k) q.pop_front();
        }

        if (size) result.push_back(nums[q.front()]);

        return result;
    }
};

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
