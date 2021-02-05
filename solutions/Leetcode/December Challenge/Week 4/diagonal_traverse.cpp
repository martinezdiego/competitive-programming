class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int N = matrix.size();
        if (N == 0) return ans;
        int M = matrix[0].size();
        int row, col;
        row = col = 0;
        for (int i = 0; i < N * M; i++) {
            ans.push_back(matrix[row][col]);
            if ((row + col)%2 == 0) {
                // if last column the go next row
                if (col == M - 1) {
                    row++;
                }
                // if fist row but not last column
                else if (row == 0) {
                    col++;
                }
                // go up
                else {
                    col++;
                    row--;
                }
            }
            else {
                // if last row then go next column
                if (row == N - 1) {
                    col++;
                }
                // if first col but not last row
                else if (col == 0) {
                    row++;
                }
                // go down
                else {
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};
