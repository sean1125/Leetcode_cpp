// leetcode 240 Search a 2D Matrix II.cpp

class Solution {
public:
    bool searchMatrix(vector<vector<int> > & m, int t, int ys, int ye, int xs, int xe) {

        if (ys > ye || xs > xe) return false;

        int ym = (ys + ye) / 2, xm = (xs + xe) / 2;

        if (m[ym][xm] == t) return true;
        if (m[ym][xm] < t) return searchMatrix(m, t, ym + 1, ye, xs, xe) || searchMatrix(m, t, ys, ym, xm + 1, xe);
        if (m[ym][xm] > t) return searchMatrix(m, t, ys, ym - 1, xs, xe) || searchMatrix(m, t, ym, ye, xs, xm - 1);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0) return false;

        int sizeY = matrix.size(), sizeX = matrix[0].size();

        return searchMatrix(matrix, target, 0, sizeY - 1, 0, sizeX - 1);
    }
};
