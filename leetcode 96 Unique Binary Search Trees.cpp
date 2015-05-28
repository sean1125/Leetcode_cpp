// leetcode 96 Unique Binary Search Trees

class Solution {
public:
    int numTrees(int start, int end, vector<int> & array) {
        if (start >= end) return 1;
        if (array[end - start] > 0) return array[end - start];

        int counter = 0, i;
        
        for (i = start; i <= end; i++)
            counter += (numTrees(start, i - 1, array) * numTrees(i + 1, end, array));

        array[end - start] = counter;
        return counter;
    }

    int numTrees(int n) {
        vector<int> array(n, -1);
        
        return numTrees(1, n, array);
    }
};
