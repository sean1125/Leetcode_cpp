// leetcode 258 Add Digits.cpp

class Solution {
public:
    int addDigits(int num) {

        if (!num) return 0;
        else return (num % 9) ? (num % 9) : 9;
    }
};
