// leetcode 109 Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);

        ListNode * faster = head, * slower = head, * prev;

        while (faster && faster->next) {
            prev = slower;
            slower = slower->next;
            faster = faster->next->next;
        }
        prev->next = NULL;

        TreeNode * root = new TreeNode(slower->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slower->next);

        prev->next = slower;

        return root;
    }
};
