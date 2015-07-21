// leetcode 146 LRU Cache.cpp

class LRUCache{
private:
    struct Node {
        int key, value;
        Node(int key, int value) : key(key), value(value) {}
    };

    int capacity, counter;
    list<Node *> l;
    map<int, list<Node *>::iterator> m;

    void moveToHead (int key) {

        Node * tmp = (* m[key]);

        l.erase(m[key]);
        l.push_front(tmp);
        m[key] = l.begin();

        return;
    }

public:
    LRUCache(int capacity) : capacity(capacity), counter(0) {}

    int get(int key) {

        if (m.find(key) == m.end()) return -1;

        moveToHead(key);

        return (* m[key])->value;
    }

    void set(int key, int value) {

        if (m.find(key) != m.end()) {
            (* m[key])->value = value;
            moveToHead(key);
        } else {
            l.push_front(new Node(key, value));
            m[key] = l.begin();
            counter++;

            if (counter > capacity) {
                m.erase(l.back()->key);
                delete l.back();
                l.pop_back();
                counter--;
            }
        }

        return;
    }
};
