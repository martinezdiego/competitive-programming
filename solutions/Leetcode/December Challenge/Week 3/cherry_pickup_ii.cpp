class Solution {
    private:
        int dp[70][70][70];
        int N, M;
        
        int f(int row, int col1, int col2, vector<vector<int>>& grid)
        {
            if (row >= N) return 0;
            if (col1 < 0 or col1 >= M) return 0;
            if (col2 < 0 or col2 >= M) return 0;
            
            if (dp[row][col1][col2] != -1) return dp[row][col1][col2];
            
            int result = grid[row][col1] + grid[row][col2];
            int mx = 0;
            if (col1 == col2) result -= grid[row][col1];
            
            for (int new_col1 = col1 - 1; new_col1 <= col1 + 1; new_col1++) {
                for (int new_col2 = col2 - 1; new_col2 <= col2 + 1; new_col2++) {
                    mx = max(mx, f(row + 1, new_col1, new_col2, grid));
                }
            }
            result += mx;
            dp[row][col1][col2] = result;
            return result;
        }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        N = grid.size();
        M = grid[0].size();
        return f(0, 0, M - 1, grid);
    }
};
