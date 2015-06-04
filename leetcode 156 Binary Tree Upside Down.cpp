// leetcode 156 Binary Tree Upside Down.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {

        if (!root) return NULL;
        if (!root->left) return root;

        TreeNode * newRoot = upsideDownBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root;
        root->left = NULL;
        root->right = NULL;

        return newRoot;
    }
};

// non-recursive
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {

        if (!root) return NULL;

        stack<TreeNode *> s;
        TreeNode * run = root, * last;

        while (run) {
            s.push(run);
            run = run->left;
        }

        root = s.top();
        s.pop();
        root->left = NULL;
        root->right = NULL;
        last = root;

        while(!s.empty()) {
            run = s.top();
            s.pop();

            last->left = run->right;
            last->right = run;
            run->left = NULL;
            run->right = NULL;

            last = run;
        }

        return root;
    }
};
