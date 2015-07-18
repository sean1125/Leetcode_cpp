// leetcode 228 Summary Ranges.cpp

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int i, j, size = nums.size();
        vector<string> result;

        for (i = 0; i < size; i += j) {
            for (j = 1; i + j < size && nums[i + j - 1] + 1 == nums[i + j]; j++);
            result.push_back(j == 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
        }

        return result;
    }
};
