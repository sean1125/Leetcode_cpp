// leetcode 225 Implement Stack using Queues.cpp

class Stack {
private:
    queue<int> q;
    queue<int> coQ;

public:
    // Push element x onto stack.
    void push(int x) {

        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {

        int tmp = q.front();
        q.pop();

        while (!q.empty()) {
            coQ.push(tmp);
            tmp = q.front();
            q.pop();
        }

        while (!coQ.empty()) {
            q.push(coQ.front());
            coQ.pop();
        }
    }

    // Get the top element.
    int top() {

        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {

        return q.empty();
    }
};
