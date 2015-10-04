// leetcode 289 Game of Life.cpp

class Solution {
public:
    int neighbor(vector<vector<int> > & board, int i, int j) {

        int counter = 0, m = board.size(), n = board[0].size();

        counter += i - 1 >= 0 && j - 1 >= 0 ? board[i - 1][j - 1] % 10 : 0;
        counter += i - 1 >= 0 ? board[i - 1][j] % 10 : 0;
        counter += i - 1 >= 0 && j + 1 < n ? board[i - 1][j + 1] % 10 : 0;

        counter += j - 1 >= 0 ? board[i][j - 1] % 10 : 0;
        counter += j + 1 < n ? board[i][j + 1] % 10 : 0;

        counter += i + 1 < m && j - 1 >= 0 ? board[i + 1][j - 1] % 10 : 0;
        counter += i + 1 < m ? board[i + 1][j] % 10 : 0;
        counter += i + 1 < m && j + 1 < n ? board[i + 1][j + 1] % 10 : 0;

        return counter;
    }

    void gameOfLife(vector<vector<int>>& board) {

        if (board.empty()) return;

        int i, j, m = board.size(), n = board[0].size(), tmp;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                tmp = neighbor(board, i, j);

                if (board[i][j]) {
                    if (tmp == 2 || tmp == 3) board[i][j] += 10;
                } else {
                    if (tmp == 3) board[i][j] += 10;
                }
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) board[i][j] /= 10;
        }

        return;
    }
};
