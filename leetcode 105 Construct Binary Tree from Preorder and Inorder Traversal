// leetcode 105 Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode * buildTree(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return NULL;

        int i;
        TreeNode * node = new TreeNode(preorder[preStart]);

        for (i = inStart; i <= inEnd; i++)
            if (inorder[i] == preorder[preStart])
                break;

        node->left = buildTree(preorder, preStart + 1, preStart + i - inStart, inorder, inStart, i - 1);
        node->right = buildTree(preorder, preEnd - inEnd + i + 1, preEnd, inorder, i + 1, inEnd);

        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size = preorder.size();
        return buildTree(preorder, 0, size - 1, inorder, 0, size - 1);
    }
};
