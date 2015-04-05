// 189 Rotate Array

class Solution {
public:
    void reverse(int num[], int start, int end) {
        int tmp;
        
        while (start < end) {
            tmp = num[start];
            num[start++] = num[end];
            num[end--] = tmp;
        }
    }

    void rotate(int nums[], int n, int k) {
        k = k % n;
        
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
