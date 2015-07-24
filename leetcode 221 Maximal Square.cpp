// leetcode 221 Maximal Square.cpp

class Solution {
public:
    #define min(a, b, c) ((a < b ? a : b) < c ? (a < b ? a : b) : c)

    int maximalSquare(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;

        int x = matrix[0].size(), y = matrix.size();
        int i, j, max = 0;
        vector<vector<int> > sum(y, vector<int> (x, 0));

        for (i = 0; i < y; i++) {
            for (j = 0; j < x; j++) {
                if (!i || !j) sum[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '0') sum[i][j] = 0;
                else sum[i][j] = min(sum[i - 1][j], sum[i][j - 1], sum[i - 1][j - 1]) + 1;

                max = sum[i][j] > max ? sum[i][j] : max;
            }
        }

        return max * max;
    }
};
