// leetcode 233 Number of Digit One.cpp

class Solution {
public:
    int countDigitOne(int n) {

        int counter = 0, m = 1;

        while (m <= n && m <= 1000000000) {
            if (n / m % 10 == 0) counter += n / m / 10 * m;
            else if (n / m % 10 == 1) counter += n / m / 10 * m + n % m + 1;
            else counter += (n / m / 10 + 1) * m;

            m *= 10;
        }

        return counter;
    }
};
