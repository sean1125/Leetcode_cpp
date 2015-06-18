// leetcode 223 Rectangle Area.cpp

class Solution {
public:
    int interval(int l0, int r0, int l1, int r1) {

        if (r0 <= l1 || r1 <= l0) return 0;
        else if (l0 <= l1 && r1 <= r0) return r1 - l1;
        else if (l1 <= l0 && r0 <= r1) return r0 - l0;
        else if (l0 <= l1) return r0 - l1;
        else if (l1 <= l0) return r1 - l0;
        else return 0;
    }

    int area(int A, int B, int C, int D) {
        return (D - B) * (C - A);
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        return area(A, B, C, D) + area(E, F, G, H) - interval(A, C, E, G) * interval(B, D, F, H);
    }
};
