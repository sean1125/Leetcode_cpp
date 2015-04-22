// leetcode 103 Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;

        vector<int> array;
        stack<TreeNode *> s1;
        bool order =true;
        TreeNode * tmp;
        s1.push(root);
        int size = 1;

        while (!s1.empty()) {
            stack<TreeNode *> s2;

            while (size--) {
                tmp = s1.top();
                s1.pop();
                array.push_back(tmp->val);

                if (true == order) {
                    if (tmp->left) s2.push(tmp->left);
                    if (tmp->right) s2.push(tmp->right);
                } else {
                    if (tmp->right) s2.push(tmp->right);
                    if (tmp->left) s2.push(tmp->left);
                }
            }

            size = s2.size();
            s1 = s2;
            result.push_back(array);
            array.clear();
            order = !order;
        }

        return result;
    }
};
