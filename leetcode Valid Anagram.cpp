// leetcode Valid Anagram.cpp

class Solution {
public:
    bool isAnagram(string s, string t) {

        int size = s.size(), i;
        vector<int> times(26, 0);

        if (size != t.size()) return false;

        for (i = 0; i < size; i++) times[s[i] - 'a']++;

        for (i = 0; i < size; i++) {
            int tmp = t[i] - 'a';
            times[tmp]--;
            if (times[tmp] < 0) return false;
        }

        for (i = 0; i < 26; i++)
            if (times[i] != 0) return false;

        return true;
    }
};
