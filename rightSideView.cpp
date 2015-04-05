// 199 Binary Tree Right Side View

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        
        if (root == NULL)
            return result;
            
        int counter = 0, remain = 1;
        queue<TreeNode *> Q;
        Q.push(root);
        TreeNode * tmp;
        
        while (Q.empty() != true) {
            tmp = Q.front();
            
            if (tmp->left != NULL) {
                Q.push(tmp->left);
                counter++;
            }
            if (tmp->right != NULL) {
                Q.push(tmp->right);
                counter++;
            }
            
            Q.pop();
            remain--;
            
            if (remain == 0) {
                remain = counter;
                counter = 0;
                result.push_back(tmp->val);
            }
        }
        
        return result;
    }
};
