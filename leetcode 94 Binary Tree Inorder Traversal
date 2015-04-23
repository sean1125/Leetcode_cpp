// leetcode 94 Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode * tmp = root;
        stack<TreeNode *> s;
        
        while (!s.empty() || tmp) {
            if (tmp) {
                s.push(tmp);
                tmp = tmp->left;
            } else {
                tmp = s.top();
                s.pop();
                result.push_back(tmp->val);
                tmp = tmp->right;
            }
        }
        
        return result;
    }
};
