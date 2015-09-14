// leetcode  32 Longest Valid Parentheses.cpp

class Solution {
public:
    int longestValidParentheses(string s) {

        int i, j, size = s.size(), max = 0;
        int * dp = new int[size + 1];

        dp[0] = 0;

        for (i = 1; i <= size; i++) {
            j = i - 1 - dp[i - 1] - 1;

            if (j < 0 || s[i - 1] == '(' || s[j] == ')') dp[i] = 0;
            else dp[i] = 2 + dp[j] + dp[i - 1];

            max = max < dp[i] ? dp[i] : max;
        }

        return max;
    }
};
