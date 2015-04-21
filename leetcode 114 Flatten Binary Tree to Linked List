// leetcode 114 Flatten Binary Tree to Linked List

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
    void flatten(TreeNode *root) {
        TreeNode * rightEnd;
        
        while (root) {
            if (root->left) {
                rightEnd = root->left;
                while (rightEnd->right)
                    rightEnd = rightEnd->right;
                
                rightEnd->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            
            root = root->right;
        }
    }
};
