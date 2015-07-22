// leetcode 240 Search a 2D Matrix II.cpp

// solution 1

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty()) return false;

        int y = matrix.size(), i = 0, j = matrix[0].size() - 1;

        while (i < y && j >= 0) {
            if (matrix[i][j] == target) return true;
            matrix[i][j] < target ? i++ : j--;
        }

        return false;
    }
};

// solution 2

class Solution {
public:
    bool searchMatrix(vector<vector<int> > & m, int t, int ys, int ye, int xs, int xe) {

        if (ys > ye || xs > xe || t < m[ys][xs] || t > m[ye][xe]) return false;

        int ym = (ys + ye) / 2, xm = (xs + xe) / 2;
        int mid = m[ym][xm];

        if (mid == t) return true;
        if (mid < t) return searchMatrix(m, t, ym + 1, ye, xs, xe) || searchMatrix(m, t, ys, ym, xm + 1, xe);
        if (mid > t) return searchMatrix(m, t, ys, ym - 1, xs, xe) || searchMatrix(m, t, ym, ye, xs, xm - 1);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        return !matrix.empty() && searchMatrix(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
};

// solution 3

class Solution {
public:
    bool searchMatrix(vector<int> & array, int target, int start, int end) {

        if (start > end) return false;

        int mid = (start + end) / 2;

        if (array[mid] == target) return true;
        else if (array[mid] < target) return searchMatrix(array, target, mid + 1, end);
        else return searchMatrix(array, target, start, mid - 1);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0) return false;

        int sizeY = matrix.size(), sizeX = matrix[0].size(), i;

        for (i = 0; i < sizeY; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][sizeX - 1] && searchMatrix(matrix[i], target, 0, sizeX - 1))
                return true;
        }

        return false;
    }
};
