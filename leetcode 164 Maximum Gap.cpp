// leetcode 164 Maximum Gap.cpp

class Solution {
public:
    void countingSort(vector<int> & nums, int m) {

        int i, size = nums.size();
        vector<int> counter(10, 0);
        vector<int> sorted(size);

        for (i = 0; i < size; i++) counter[nums[i] / m % 10]++;

        for (i = 1; i < 10; i++) counter[i] += counter[i - 1];

        for (i = size - 1; i >= 0; i--) {
            int tmp = nums[i] / m % 10;
            sorted[counter[tmp] - 1] = nums[i];
            counter[tmp]--;
        }

        nums = sorted;

        return;
    }

    void radixSort(vector<int> & nums) {

        int m, i, size = nums.size(), max = 0;

        for (i = 0; i < size; i++) max = max > nums[i] ? max : nums[i];

        for (m = 1; m <= max && m <= 1000000000; m *= 10) countingSort(nums, m);

        return;
    }

    int maximumGap(vector<int>& nums) {

        int size = nums.size(), i, max = 0;

        radixSort(nums);

        for (i = 0; i < size - 1; i++) {
            int tmp = nums[i + 1] - nums[i];
            max = max > tmp ? max : tmp;
        }

        return max;
    }
};
