// leetcode 191 Number of 1 Bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0, i;

        while (n != 0) {
            counter += n % 2;
            n >>= 1;
        }
        
        return counter;
    }
};
