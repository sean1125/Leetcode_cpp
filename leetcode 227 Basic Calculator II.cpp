// leetcode 227 Basic Calculator II.cpp

class Solution {
public:
    void calculate(stack<int> & nums, stack<char> & oprs) {

        if (oprs.empty() || oprs.top() == '+' || oprs.top() == '-') return;

        int tmp = nums.top();
        nums.pop();
        
        if (oprs.top() == '*') nums.top() *= tmp;
        else nums.top() /= tmp;

        oprs.pop();
    }

    int calculate(string s) {

        stack<int> nums;
        stack<char> oprs;
        bool isNum = false;
        int i, size = s.size(), tmp = 0;

        for (i = 0; i < size; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                calculate(nums, oprs);
                oprs.push(s[i]);
                isNum = false;
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (isNum) nums.top() = nums.top() * 10 + s[i] - '0';
                else nums.push(s[i] - '0');
                isNum = true;
            }
        }

        calculate(nums, oprs);

        while (!oprs.empty()) {
            if (oprs.top() == '+') tmp += nums.top();
            else tmp -= nums.top();

            nums.pop();
            oprs.pop();
        }

        return tmp + nums.top();
    }
};
