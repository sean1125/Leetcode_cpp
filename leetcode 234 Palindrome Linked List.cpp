// leetcode 234 Palindrome Linked List.cpp

// O(n) time and O(1) space

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
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) return true;

        ListNode * slower = head;
        ListNode * faster = head;

        while (faster->next && faster->next->next) {
            slower = slower->next;
            faster = faster->next->next;
        }

        ListNode * newHead = slower->next;
        slower->next = NULL;

        ListNode * curr;
        ListNode * next = newHead;
        newHead = NULL;

        while (next) {
            curr = next;
            next = next->next;
            curr->next = newHead;
            newHead = curr;
        }

        while (newHead) {
            if (head->val != newHead->val) return false;
            head = head->next;
            newHead = newHead->next;
        }

        return true;
    }
};
