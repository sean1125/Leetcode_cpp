// leetcode 111 Minimum Depth of Binary Tree.cpp

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
    int minDepth(TreeNode* root) {

        if (!root) return 0;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (!leftDepth) return rightDepth + 1;
        if (!rightDepth) return leftDepth + 1;

        return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
    }
};
