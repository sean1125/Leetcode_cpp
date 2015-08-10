// leetcode 101 Symmetric Tree.cpp

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
    bool isSymmetric(TreeNode * left, TreeNode * right) {

        if (!left && !right) return true;
        if (!left && right || left && !right) return false;
        if (left->val != right->val) return false;

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (!root) return true;
        else return isSymmetric(root->left, root->right); 
    }
};
