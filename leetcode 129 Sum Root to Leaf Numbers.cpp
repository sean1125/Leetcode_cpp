// leetcode 129 Sum Root to Leaf Numbers

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void sumNumbers(TreeNode * curr, int number, vector<int> & array) {
        number *= 10;
        number += curr->val;
        
        if (curr->left) sumNumbers(curr->left, number, array);
        if (curr->right) sumNumbers(curr->right, number, array);
        if (!curr->left && !curr->right) array.push_back(number);
    }

    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        
        vector<int> array;
        sumNumbers(root, 0, array);
        int i, counter = 0, size = array.size();
        
        for (i = 0; i < size; i++)
            counter += array[i];
            
        return counter;
    }
};
