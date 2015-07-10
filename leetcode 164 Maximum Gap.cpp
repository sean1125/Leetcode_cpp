// leetcode 164 Maximum Gap.cpp

class Solution {
public:
    void countingSort(vector<int> & nums, int m) {

        int i, j, size = nums.size();
        vector<int> counter(10, 0);
        vector<int> sorted(size);

        for (i = 0; i < size; i++)
            counter[nums[i] / m % 10]++;

        for (j = 1; j < 10; j++)
            counter[j] += counter[j - 1];

        for (i = size - 1; i >= 0; i--) {
            sorted[counter[nums[i] / m % 10] - 1] = nums[i];
            counter[nums[i] / m % 10]--;
        }

        nums = sorted;
    }

    void sort(vector<int> & nums) {

        int m, i, size = nums.size(), max = 0;

        for (i = 0; i < size; i++)
            max = max < nums[i] ? nums[i] : max;

        for (m = 1; m <= max && m <= 1000000000; m *= 10)
            countingSort(nums, m);
    }

    int maximumGap(vector<int>& nums) {

        int size = nums.size(), i;
        if (size < 2) return 0;

        sort(nums);

        int max = 0;

        for (i = 0; i < size - 1; i++)
            max = max < (nums[i + 1] - nums[i]) ? (nums[i + 1] - nums[i]) : max;

        return max;
    }
};
