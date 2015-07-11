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
    TreeNode * LCA (TreeNode * root, TreeNode * p, TreeNode * q) {

        if (p->val < root->val && root->val < q->val) return root;
        if (p->val > root->val) return LCA(root->right, p, q);
        if (root->val > q->val) return LCA(root->left, p, q);
        if (p->val == root->val || q->val == root->val) return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root || !p || !q) return NULL;

        if (p->val < q->val) return LCA(root, p, q);
        else  return LCA(root, q, p);
    }
};
