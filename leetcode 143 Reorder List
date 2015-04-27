// leetcode 143 Reorder List

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
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode * faster = head, * slower = head;

        while (faster->next && faster->next->next) {
            faster = faster->next->next;
            slower = slower->next;
        }

        ListNode * run0 = slower->next, * run1 = NULL, * next = run0;
        slower->next = NULL;

        do {
            next = next->next;
            run0->next = run1;
            run1 = run0;
            run0 = next;
        } while (next);

        run0 = head;
        next = head;

        do {
            next = next->next;
            run0->next = run1;
            run1 = run1->next;
            run0->next->next = next;
            run0 = next;
        } while (run1);
    }
};
