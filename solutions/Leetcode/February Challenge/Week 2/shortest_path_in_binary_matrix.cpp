 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        queue<pair<int, int> > q;
        pair<int, int> cur = {0, 0};
        q.push(cur);
        if (grid[0][0] == 1 or grid[N - 1][N - 1] == 1) {
            return -1;
        }
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int r = i + cur.first, c = j + cur.second;
                    if (r < 0 or r >= N or c < 0 or c >= N or grid[r][c] != 0) {
                        continue;
                    }
                    grid[r][c] = grid[cur.first][cur.second] + 1;
                    q.push({r, c});
                    if (r == N - 1 and c == N - 1) {
                        return grid[N - 1][N - 1];
                    }
                }
            }
        }
        return -1;
    }
};
