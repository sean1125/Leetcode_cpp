// leetcode 232 Implement Queue using Stacks.cpp

class Queue {
private:
    stack<int> s;
    stack<int> coS;
    int first;

public:
    Queue() : first(-1) {}

    // Push element x to the back of queue.
    void push(int x) {

        s.push(x);
        
        if (first == -1) first = x;
    }

    // Removes the element from in front of queue.
    void pop(void) {

        int tmp;

        while (!s.empty()) {
            tmp = s.top();
            s.pop();
            coS.push(tmp);
        }

        coS.pop();

        if (!coS.empty()) first = coS.top();
        else first = -1;

        while (!coS.empty()) {
            tmp = coS.top();
            coS.pop();
            s.push(tmp);
        }
    }

    // Get the front element.
    int peek(void) {

        return first;
    }

    // Return whether the queue is empty.
    bool empty(void) {

        return s.empty();
    }
};
