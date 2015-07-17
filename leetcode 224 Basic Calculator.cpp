// leetcode 224 Basic Calculator.cpp

class Solution {
public:
    int calculate(stack<int> & num, stack<char> & opr) {

        int result = 0, tmp;

        while (!opr.empty() && opr.top() != '(') {
            if (opr.top() == '+') result += num.top();
            else result -= num.top();

            num.pop();
            opr.pop();
        }

        result += num.top();
        num.pop();
        return result;
    }

    int calculate(string s) {

        int i, tmp, size = s.size();
        stack<int> num;
        stack<char> opr;
        bool isNum = false;

        for (i = 0; i < size; i++) {
            switch(s[i]) {
                case ' ':
                    break;
                case '(':
                    opr.push('(');
                    isNum = false;
                    break;
                case '+':
                    opr.push('+');
                    isNum = false;
                    break;
                case '-':
                    opr.push('-');
                    isNum = false;
                    break;
                case ')':
                    tmp = calculate(num, opr);
                    opr.pop();
                    num.push(tmp);
                    break;
                default:
                    if (isNum) num.top() = num.top() * 10 + (s[i] -'0');
                    else num.push(s[i] -'0');
                    isNum = true;
            }
        }

        return calculate(num, opr);
    }
};
