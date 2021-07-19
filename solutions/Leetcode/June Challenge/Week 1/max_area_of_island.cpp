class Solution {
    void bfs(int i, int j, vector<vector<int>>& grid, int & cnt)
    {
        cnt++;
        grid[i][j] = 0;
        if (i + 1 < grid.size() and grid[i + 1][j] == 1) bfs(i + 1, j, grid, cnt);
        if (i - 1 >= 0 and grid[i - 1][j] == 1) bfs(i - 1, j, grid, cnt);
        if (j + 1 < grid[0].size() and grid[i][j + 1] == 1) bfs(i, j + 1, grid, cnt);
        if (j - 1 >= 0 and grid[i][j - 1] == 1) bfs(i, j - 1, grid, cnt);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    int cur = 0;
                    bfs(i, j, grid, cur);
                    ans = max (ans, cur);
                }
            }
        }
        return ans;
    }
}; 
