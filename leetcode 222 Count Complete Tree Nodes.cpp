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

        TreeNode * left = root, * right = root;
        int i, counter = 1;

        for (i = 0; left && right; i++) {
            left = left->left;
            right = right->right;
        }

        if (!left && !right) {
            while (i--) counter *= 2;
            return counter - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
