// leetcode 257 Binary Tree Paths.cpp

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
    void binaryTreePaths(TreeNode * root, vector<string> & result, string str) {

        if (!root) return;

        str += to_string(root->val);

        if (!root->left && !root->right) {
            result.push_back(str);
        } else {
            binaryTreePaths(root->left, result, str + "->");
            binaryTreePaths(root->right, result, str + "->");
        }

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> result;

        binaryTreePaths(root, result, "");

        return result;

    }
};
