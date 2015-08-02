// leetcode 241 Different Ways to Add Parentheses.cpp

class Solution {
public:
    int toInt(string & input, int start, int end) {

        int i, counter = 0;

        for (i = start; i <= end; i++) {
            counter *= 10;
            counter += (input[i] - '0');
        }

        return counter;
    }

    void calculate(vector<int> & result, vector<int> & half0, vector<int> & half1, char c) {

        int size0 = half0.size(), size1 = half1.size(), i, j;

        for (i = 0; i < size0; i++) {
            for (j = 0; j < size1; j++) {
                switch (c) {
                    case '+': result.push_back(half0[i] + half1[j]); break;
                    case '-': result.push_back(half0[i] - half1[j]); break;
                    case '*': result.push_back(half0[i] * half1[j]); break;
                    case '/': result.push_back(half0[i] / half1[j]); break;
                }
            }
        }

        return;
    }

    vector<int> diffWaysToCompute(string & input, int start, int end) {

        int i;
        vector<int> half0, half1, result;

        for (i = start; i <= end; i++) {
            if(input[i] < '0' || input[i] > '9') {
                half0 = diffWaysToCompute(input, start, i - 1);
                half1 = diffWaysToCompute(input, i + 1, end);
                calculate(result, half0, half1, input[i]);
            }
        }

        if (result.empty()) result.push_back(toInt(input, start, end));

        return result;
    }

    vector<int> diffWaysToCompute(string input) {

        return diffWaysToCompute(input, 0, input.size() - 1);
    }
};
