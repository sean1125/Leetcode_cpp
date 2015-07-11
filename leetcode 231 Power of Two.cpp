// leetcode 231 Power of Two.cpp

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n <= 0) return false;

        bool flag = false;

        while (n > 0 && !flag) {
            flag = n % 2;
            n >>= 1;
        }

        if (n > 0) return false;
        else return true;
    }
};
