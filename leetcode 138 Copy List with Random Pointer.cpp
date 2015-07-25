// leetcode 138 Copy List with Random Pointer.cpp

// solution 1, space complexity O(1).

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        RandomListNode * run = head, * tmp;

        if (!head) return NULL;

        while (run) {
            tmp = new RandomListNode(run->label);
            tmp->next = run->next;
            run->next =tmp;
            run = tmp->next;
        }

        run = head;

        while (run) {
            if (run->random) run->next->random = run->random->next;
            run = run->next->next;
        }

        RandomListNode * newHead = head->next;
        run = head;
        tmp = newHead;

        while (run) {
            run->next = run->next->next;
            run = run->next;

            if (tmp->next) tmp->next = tmp->next->next;
            tmp = tmp->next;
        }

        return newHead;
    }
};

// solution 2, space complexity O(n).

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        RandomListNode * run = head;
        unordered_map<RandomListNode *, RandomListNode *> m;

        if (!head) return NULL;

        while (run) {
            m[run] = new RandomListNode(run->label);
            run = run->next;
        }

        run = head;

        while (run->next) {
            m[run]->next = m[run->next];
            m[run]->random = m[run->random];
            run = run->next;
        }

        m[run]->next = NULL;
        m[run]->random = m[run->random];

        return m[head];
    }
};
