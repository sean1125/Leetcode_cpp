// leetcode 215 Kth Largest Element in an Array.cpp

class Solution {
public:

    int heapSize;

    void swap(int & a, int & b) {

        int tmp = a;
        a = b;
        b = tmp;

        return;
    }

    void maintain(vector<int> & nums, int i) {

        int l = 2 * i + 1, r = 2 * i + 2, size = heapSize, largest;

        largest = l < size && nums[i] < nums[l] ? l : i;
        largest = r < size && nums[largest] < nums[r] ? r : largest;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            maintain(nums, largest);
        }

        return;
    }

    int findKthLargest(vector<int>& nums, int k) {

        int i, size = nums.size();

        heapSize = size;

        for (i = size / 2 - 1; i >= 0; i--) maintain(nums, i);

        for (i = 0; i < k; i++) {
            swap(nums[0], nums[size - i - 1]);
            heapSize--;
            maintain(nums, 0);
        }

        return nums[size - k];
    }
};
