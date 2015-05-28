// leetcode 98 Validate Binary Search Tree

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
    bool isValidBST(TreeNode * curr, TreeNode * min, TreeNode * max) {
        if (!curr) return true;
        if (min && curr->val <= min->val || max && curr->val >= max->val) return false;
        
        return isValidBST(curr->left, min, curr) && isValidBST(curr->right, curr, max);
    }

    bool isValidBST(TreeNode * root) {
        return isValidBST(root, NULL, NULL);
    }
};
