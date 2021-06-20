// Given a 2D matrix matrix, handle multiple queries of the following type:
// 
// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:
// 
// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        dp.assign(N + 1, vector<int>(M + 1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // dp[i][j + 1] = dp[i][j] + matrix[i][j];
                // Sum(ABCD)=Sum(OD)−Sum(OB)−Sum(OC)+Sum(OA)
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] + matrix[i][j] - dp[i][j];

            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // int sum = 0;
        // for (int i = row1; i <= row2; i++) {
        //     sum += dp[i][col2 + 1] - dp[i][col1];
        // }
        // return sum;
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
