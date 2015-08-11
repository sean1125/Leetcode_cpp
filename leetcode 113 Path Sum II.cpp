// leetcode 113 Path Sum II

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
    void pathSum(TreeNode * curr, int sum, vector<vector<int> > & result, vector<int> & array) {

        sum -= curr->val;

        array.push_back(curr->val);

        if (curr->left) pathSum(curr->left, sum, result, array);
        if (curr->right) pathSum(curr->right,sum, result, array);
        if (!curr->left && !curr->right && !sum) result.push_back(array);

        array.pop_back();

        return;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {

        vector<vector<int> > result;
        vector<int> array;

        if (!root) return result;

        pathSum(root, sum, result, array);

        return result;
    }
};
