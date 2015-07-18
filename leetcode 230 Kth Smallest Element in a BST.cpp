// leetcode 230 Kth Smallest Element in a BST.cpp

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
    TreeNode * traversal(TreeNode * root, int & k) {

        if (!root) return NULL;

        TreeNode * tmp;

        tmp = traversal(root->left, k);
        if (tmp) return tmp;

        if (--k == 0) return root;

        tmp = traversal(root->right, k);
        if (tmp) return tmp;

        return NULL;
    }

    int kthSmallest(TreeNode* root, int k) {

        return traversal(root, k)->val;
    }
};
