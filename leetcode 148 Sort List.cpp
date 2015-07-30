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
    ListNode * merge(ListNode * l1, ListNode * l2) {
    	
    	ListNode * guard = new ListNode(-1), * run = guard;
    
    	while (l1 && l2) {
    		if (l1->val < l2->val) {
    			run->next = l1;
    			l1 = l1->next;
    		} else {
    			run->next = l2;
    			l2 = l2->next;
    		}
    
    		run = run->next;
    	}
    
    	if (l1) run->next = l1;
    	if (l2) run->next = l2;
    
    	run = guard->next;
    
    	delete guard;
    
    	return run;
    }
    
    ListNode * sort(ListNode * & head, int length) {
    
    	if (length == 1) {
    		ListNode * tmp = head;
    		head = head->next;
    		tmp->next = NULL;
    		return tmp;
    	}
    
    	ListNode * left = sort(head, length / 2);
    	ListNode * right = sort(head, length - length / 2);
    
    	return merge(left, right);
    }
    
    ListNode * sortList(ListNode * head) {
    
    	if (!head) return NULL;
    
    	int length = 0;
    	ListNode * run;
    
    	for (run = head; run; run = run->next) length++;
    
    	return sort(head, length);
    }
};
