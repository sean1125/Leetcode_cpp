// leetcode 116 Populating Next Right Pointers in Each Node

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        int counter = 0, size = 1;
        TreeLinkNode * tmp;
        queue<TreeLinkNode *> q;
        q.push(root);
        
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            size--;
            
            if (tmp->left) {
                q.push(tmp->left);
                counter++;
            }
            if (tmp->right) {
                q.push(tmp->right);
                counter++;
            }
            
            if (size == 0) {
                size = counter;
                counter = 0;
            } else {
                tmp->next = q.front();
            }
        }
    }
};
