/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void sumNumbers(TreeNode * root, int num, int & sum) {

        num *=10;
        num += root->val;

        if (root->left) sumNumbers(root->left, num, sum);
        if (root->right) sumNumbers(root->right, num, sum);
        if (!root->left && !root->right) sum += num;

        return;
    }

    int sumNumbers(TreeNode* root) {

        if (!root) return 0;

        int sum = 0;

        sumNumbers(root, 0, sum);

        return sum;
    }
};
