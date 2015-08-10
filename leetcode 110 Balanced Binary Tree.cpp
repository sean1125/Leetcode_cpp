// leetcode 110 Balanced Binary Tree.cpp

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
    int depth(TreeNode * root) {

        if (!root) return 0;

        int l = depth(root->left);
        int r = depth(root->right);

        if (l == -1 || r == -1) return -1;

        if(l == r || l == r + 1 || l + 1 == r) return (l > r) ? (l + 1) : (r + 1);
        else return -1;
    }

    bool isBalanced(TreeNode* root) {

        if (depth(root) == -1) return false;
        else return true;
    }
};
