// leetcode 199 Binary Tree Right Side View.cpp

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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        TreeNode * tmp;
        queue<TreeNode *> q;
        int counter = 1;

        if (root) q.push(root);

        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            counter--;

            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);

            if (!counter) {
                result.push_back(tmp->val);
                counter = q.size();
            }
        }

        return result;
    }
};
