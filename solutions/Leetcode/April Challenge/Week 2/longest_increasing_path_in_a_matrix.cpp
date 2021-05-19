// Given an m x n integers matrix, return the length of the longest increasing path in matrix.
// 
// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

class Solution {
    int dp[200][200];
    
    int dfs(int i, int j, vector<vector<int>> & m)
    {
        int N = m.size();
        int M = m[0].size();
        
        if (dp[i][j]) return dp[i][j];
        
        int ans = 1;
        
        if (i - 1 >= 0 and m[i][j] < m[i - 1][j]) ans = max(ans, dfs(i - 1, j, m) + 1);
        if (i + 1 < N and m[i][j] < m[i + 1][j]) ans = max(ans, dfs(i + 1, j, m) + 1);
        if (j - 1 >= 0 and m[i][j] < m[i][j - 1]) ans = max(ans, dfs(i, j - 1, m) + 1);
        if (j + 1 < M and m[i][j] < m[i][j + 1]) ans = max(ans, dfs(i, j + 1, m) + 1);
        
        return dp[i][j] = ans;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // memset(dp, 0, sizeof dp);
        int N = matrix.size();
        int M = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
}; 
