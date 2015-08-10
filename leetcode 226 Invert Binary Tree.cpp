// leetcode 226 Invert Binary Tree.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // iteration
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (!root) return NULL;

        TreeNode * tmp, * curr;
        stack<TreeNode *> s;

        s.push(root);

        while (!s.empty()) {
            curr = s.top();
            s.pop();

            tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;

            if (curr->left) s.push(curr->left);
            if (curr->right) s.push(curr->right);
        }

        return root;
    }
};


// recursive

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (!root) return NULL;

        TreeNode * tmp;

        tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
