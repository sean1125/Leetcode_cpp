// leetcode 144 Binary Tree Preorder Traversal

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) return result;

        TreeNode * tmp;
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            result.push_back(tmp->val);

            if (tmp->right) s.push(tmp->right);
            if (tmp->left) s.push(tmp->left);
        }
        
        return result;
    }
};
