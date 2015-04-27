// leetcode 86 Partition List

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
    ListNode* partition(ListNode* head, int x) {
        ListNode * head1 = new ListNode(0);
        ListNode * head2 = new ListNode(0);
        ListNode * run = head, * run1 = head1, * run2 = head2;

        while (run) {
            if (run->val < x) {
                run1->next = run;
                run1 = run1->next;
                run = run->next;
            } else {
                run2->next = run;
                run2 = run2->next;
                run = run->next;
            }
        }

        run1->next = head2->next;
        head = head1->next;
        run2->next = NULL;

        delete head1;
        delete head2;

        return head;
    }
};
