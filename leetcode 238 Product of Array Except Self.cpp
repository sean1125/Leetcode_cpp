// leetcode 238 Product of Array Except Self.cpp

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int size = nums.size(), tmp, i;
        vector<int> result(size);

        tmp = 1;
        result[0] = 1;

        for (i = 1; i < size; i++) {
            tmp *= nums[i - 1];
            result[i] = tmp;
        }

        tmp = 1;

        for (i = size - 1; i >= 0; i--) {
            result[i] *= tmp;
            tmp *= nums[i];
        }

        return result;
    }
};
