// leetcode 92 Reverse Linked List II

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int i;
        ListNode * guard = new ListNode(0);
        guard->next = head;
        ListNode * run = guard, * next, * tmp1, * tmp2 = NULL, * tmp3;

        for (i = 0; i < m - 1; i++)
            run = run->next;

        tmp1 = run;
        tmp3 = run->next;
        run = run->next;
        next = run->next;

        for (; i < n; i++) {
            run->next = tmp2;
            tmp2 = run;
            run = next;
            if (next) next = next->next;
        }

        tmp1->next = tmp2;
        tmp3->next = run;
        
        head = guard->next;
        delete guard;

        return head;
    }
};
