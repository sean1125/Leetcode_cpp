// leetcode 216 Combination Sum III.cpp

class Solution {
public:
    void combinationSum3(vector<vector<int> > & result, vector<int> & array, int k, int n, int start) {

        if (!k && !n) {
            result.push_back(array);
            return;
        }

        if (start == 10 || n <= 0) return;

        int i;

        for (i = start; i < 10; i++) {
            array.push_back(i);
            combinationSum3(result, array, k - 1, n - i, i + 1);
            array.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int> > result;
        vector<int> array;

        combinationSum3(result, array, k, n, 1);

        return result;
    }
};
