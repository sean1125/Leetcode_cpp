// leetcode 235 Lowest Common Ancestor of a Binary Search Tree.cpp

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

        if (p->val == root->val) return root;
        if (q->val == root->val) return root;
    }
    
    TreeNode * findRoot(TreeNode * p, TreeNode * q) {
        
        TreeNode * tmp = p;
        
        while (tmp && tmp->val == q->val) {
            if (tmp == q) return p;
            tmp = tmp->right;
        }
        
        return q;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root || !p || !q) return NULL;

        if (p->val == q->val) return findRoot(p, q);

        if (p->val < q->val) return LCA(root, p, q);
        else  return LCA(root, q, p);
    }
};
