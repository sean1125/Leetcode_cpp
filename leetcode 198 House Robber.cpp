// leetcode 198 House Robber

class Solution {
#define max(a, b) (a > b ? a : b)
    
public:
    int rob(vector<int> & num, vector<int> & values, int house) {
        if (house == 0) values[house] = num[0];
        else if (house == 1) values[house] = max(num[0], num[1]);

        if (values[house] != -1)
            return values[house];

        int valueLessOne = rob(num, values, house - 1);
        int valueLessTwo = rob(num, values, house - 2);
        
        values[house] = max(valueLessOne, valueLessTwo + num[house]);
            
        return values[house];
    }

    int rob(vector<int> & num) {
        int size = num.size();
        
        if (size == 0)
            return 0;
        
        vector<int> values(size, -1);
        return rob(num, values, size - 1);
    }
};
