// leetcode 219 Contains Duplicate II.cpp

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int i, size = nums.size();
        unordered_map<int, int> m;

        for (i = 0; i < size; i++) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k) return true;
                else m[nums[i]] = i;
            } else {
                m[nums[i]] = i;
            }
        }

        return false;
    }
};
