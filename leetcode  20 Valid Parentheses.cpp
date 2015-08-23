// leetcode  20 Valid Parentheses.cpp

class Solution {
public:
    bool isValid(string s) {

        int i, size = s.size();
        stack<char> st;

        for (i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()
                    || s[i] == ')' && st.top() != '('
                    || s[i] == ']' && st.top() != '['
                    || s[i] == '}' && st.top() != '{')
                    return false;
                st.pop();
            }
        }

        if (st.empty()) return true;
        else return false;
    }
};
