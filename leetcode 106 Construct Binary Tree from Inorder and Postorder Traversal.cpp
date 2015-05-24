// leetcode 106 Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode * buildTree(vector<int> & inorder, int inStart, int inEnd, vector<int> & postorder, int postStart, int postEnd) {
        if (inStart > inEnd) return NULL;

        int i;
        TreeNode * node = new TreeNode(postorder[postEnd]);

        for (i = inStart; i <= inEnd; i++)
            if (inorder[i] == postorder[postEnd])
                break;

        node->left = buildTree(inorder, inStart, i - 1, postorder, postStart, postStart + i - inStart - 1);
        node->right = buildTree(inorder, i + 1, inEnd, postorder, postEnd - inEnd + i, postEnd - 1);

        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        return buildTree(inorder, 0, size - 1, postorder, 0, size - 1);
    }
};
