// leetcode 229 Majority Element II.cpp

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int num0 = -1, num1 = -1;
        int counter0 = 0, counter1 = 0;
        int i, size = nums.size();
        vector<int> result;

        for (i = 0; i < size; i++) {
            if (nums[i] == num0) {
                counter0++;
            } else if (nums[i] == num1) {
                counter1++;
            } else {
                if (!counter0) {
                    num0 = nums[i];
                    counter0 = 1;
                } else if (!counter1) {
                    num1 = nums[i];
                    counter1 = 1;
                } else {
                    counter0--;
                    counter1--;
                }
            }
        }

        counter0 = 0;
        counter1 = 0;

        for (i = 0; i < size; i++) {
            if (nums[i] == num0) counter0++;
            else if (nums[i] == num1) counter1++;
        }

        if (counter0 > size / 3) result.push_back(num0);
        if (counter1 > size / 3) result.push_back(num1);

        return result;
    }
};
