// leetcode 24 Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || ! head->next) return head;
        
        ListNode * node = head->next;
        head->next = node ->next;
        node->next = head;
        
        node->next->next = swapPairs(node->next->next);
        
        return node;
    }
};
