// leetcode 217 Contains Duplicate.cpp

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int i, size = nums.size();
        unordered_set<int> s;

        for (i = 0; i < size; i++) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }

        return false;
    }
};
