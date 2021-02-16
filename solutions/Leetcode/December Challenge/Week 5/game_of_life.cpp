class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int N = board.size();
        int M = board[0].size();
        vector<vector<int>> initial_state(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                initial_state[i][j] = board[i][j];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int live = 0;
                for (int r = -1; r <= 1; r++) {
                    for (int c = -1; c <= 1; c++) {
                        if (r == 0 and c == 0) continue;
                        if (i+r >= 0 and i+r < N) {
                            if (j+c >= 0 and j+c < M) {
                                if (initial_state[i+r][j+c] == 1) live++;
                            }
                        }
                    }
                }
                if (initial_state[i][j] == 1) {
                    if (live < 2 or live > 3) {
                        board[i][j] = 0;
                    }
                }
                else {
                    if (live == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
   }
};
