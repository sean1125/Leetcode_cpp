// leetcode 222 Count Complete Tree Nodes.cpp

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
    int countNodes(TreeNode* root) {

        if (!root) return 0;

        int lh, rh, num = 1;
        TreeNode * left = root, * right = root;

        for (lh = 0; left; lh++)
            left = left->left;
        for (rh = 0; right; rh++)
            right = right->right;

        if (lh == rh) {
            while (lh--) num *= 2;
            return --num;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
