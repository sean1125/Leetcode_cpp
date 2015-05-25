// leetcode 202 Happy Number

class Solution {
public:
    bool isHappy(int n, map<int, bool> & isFound) {
        if (isFound[n]) return false;

        isFound[n] = true;
        int counter = 0;

        while (n > 0) {
            counter += (n % 10) * (n % 10);
            n /= 10;
        }

        if (counter == 1) return true;
        return isHappy(counter, isFound);
    }

    bool isHappy(int n) {
        map<int, bool> isFound;
        return isHappy(n, isFound);
    }
};
