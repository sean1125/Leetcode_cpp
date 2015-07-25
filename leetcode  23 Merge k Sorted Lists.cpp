// leetcode  23 Merge k Sorted Lists.cpp

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
    ListNode * merge(ListNode * run1, ListNode * run2) {

        ListNode * head = new ListNode(-1);
        ListNode * run = head;

        while (run1 && run2) {
            if (run1->val < run2->val) {
                run->next = run1;
                run1 = run1->next;
            } else {
                run->next = run2;
                run2 = run2->next;
            }

            run = run->next;
        }

        if (run1) run->next = run1;
        if (run2) run->next = run2;

        run = head->next;

        delete head;

        return run;
    }

    ListNode * mergeKLists (vector<ListNode *> & lists, int start, int end) {

        if (start == end) return lists[start];
        if (start + 1 == end) return merge(lists[start], lists[end]);

        int mid = (start + end) / 2;

        return merge(mergeKLists(lists, start, mid), mergeKLists(lists, mid + 1, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return NULL;

        return mergeKLists(lists, 0, lists.size() - 1);
    }
};
