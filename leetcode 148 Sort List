// leetcode 148 Sort List

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
    ListNode * merge(ListNode * head1, ListNode * head2) {
        ListNode * head, * run1 = head1, * run2 = head2, * run;

        if (head1->val < head2->val) {
            head = head1;
            run1 = run1->next;
        } else {
            head = head2;
            run2 = run2->next;
        }
        run = head;

        while (run1 && run2) {
            if (run1->val < run2->val) {
                run->next = run1;
                run = run->next;
                run1 = run1->next;
            } else {
                run->next = run2;
                run = run->next;
                run2 = run2->next;
            }
        }

        if (run1) run->next = run1;
        else run->next = run2;

        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;

        ListNode * faster = head, * slower = head, * prev;

        while (faster && faster->next) {
            prev = slower;
            slower = slower->next;
            faster = faster->next->next;
        }

        prev->next = NULL;
        ListNode * head1 = sortList(head);
        ListNode * head2 = sortList(slower);
        head = merge(head1, head2);

        return head;
    }
};
