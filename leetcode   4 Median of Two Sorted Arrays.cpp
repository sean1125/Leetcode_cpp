// leetcode   4 Median of Two Sorted Arrays.cpp

class Solution {
public:
      int findKthNumber(vector<int> & nums1, int start1, vector<int> & nums2, int start2, int k) {

        int size1 = nums1.size(), size2 = nums2.size();

        if (size1 - start1 > size2 - start2) return findKthNumber(nums2, start2, nums1, start1, k);
        if (size1 - start1 == 0) return nums2[start2 + k - 1];
        if (k == 1) return min(nums1[start1], nums2[start2]);

        int a = min(k / 2, size1 - start1), b = k - a;

        if (nums1[start1 + a - 1] < nums2[start2 + b - 1]) return findKthNumber(nums1, start1 + a, nums2, start2, k - a);
        else return findKthNumber(nums1, start1, nums2, start2 + b, k - b);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size(), size2 = nums2.size(), size = size1+ size2;

        if (size % 2) return findKthNumber(nums1, 0, nums2, 0, size / 2 + 1);
        else return (findKthNumber(nums1, 0, nums2, 0, size / 2) + findKthNumber(nums1, 0, nums2, 0, size / 2 + 1)) / 2.0;
    }
};
