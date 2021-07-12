class Solution {
    vector<string> board;
    vector<vector<string> > ans;
    vector<vector<int> > queens;
    int N;
    
    bool check(int r, int c)
    {   
        for (const vector<int> & q : queens)
        {
            int dx = abs(q[0] - r);
            int dy = abs(q[1] - c);
            if (dx == 0 || dy == 0 || dx == dy) return false;
        }
        return true;
    }
        
    void dfs(int r)
    {
        if (queens.size() == N) {
            ans.push_back(board);
            return;
        }
        if (r == N)
            return;
        
        for (int c = 0; c < N; c++) {
            if (check(r, c)) {
                board[r][c] = 'Q';
                queens.push_back({r, c});
                dfs(r + 1);
                board[r][c] = '.';
                queens.pop_back();
            }       
        }        
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        board.resize(N);
        for (int i = 0; i < N; i++) {
            board[i] = string(N, '.');
        }
        dfs(0);
        return ans;
    }
}; 
