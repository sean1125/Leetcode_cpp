// leetcode 107 Binary Tree Level Order Traversal II.cpp

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        queue<TreeNode *> q;
        vector<int> array;
        vector<vector<int> > result;
        TreeNode * tmp;

        if (!root) return result;

        int counter = 1;

        q.push(root);

        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            counter--;

            array.push_back(tmp->val);

            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);

            if (!counter) {
                result.push_back(array);
                array.clear();
                counter = q.size();
            }
        }

        int i = 0, j = result.size() - 1;

        while (i < j) {
            array = result[i];
            result[i++] = result[j];
            result[j--] = array;
        }

        return result;
    }
};
