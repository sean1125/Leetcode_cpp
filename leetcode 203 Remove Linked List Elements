// leetcode 203 Remove Linked List Elements

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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        if (!head->next) {
            if (head->val == val) return NULL;
            else return head;
        }

        ListNode * run = head->next, * prev = head;

        while (run) {
            if (run->val == val) {
                run = run->next;
                prev->next = run;
            } else {
                prev = run;
                run = run->next;
            }
        }

        if (head->val != val) return head;

        run = head->next;
        head->next = NULL;
        return run;
    }
};
