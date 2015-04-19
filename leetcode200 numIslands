// leetcode 200 Number of Islands

class Solution {
public:
    void numIslands(vector<vector<char> > & grid, int i, int j) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        
        if (i - 1 >= 0) numIslands(grid, i - 1, j);
        if (i + 1 < grid.size()) numIslands(grid, i + 1, j);
        if (j - 1 >= 0) numIslands(grid, i, j - 1);
        if (j + 1 < grid[0].size()) numIslands(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0) return 0;
        
        int i, j, number = 0;
        int rows = grid.size(), cols = grid[0].size();
        
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    numIslands(grid, i, j);
                    number++;
                }
            }
        }
                
        return number;
    }
};
