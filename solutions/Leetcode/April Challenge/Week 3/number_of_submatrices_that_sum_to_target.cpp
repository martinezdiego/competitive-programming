// Given a matrix and a target, return the number of non-empty submatrices that sum to target.
// 
// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
// 
// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int N = matrix.size();
        int M = matrix[0].size();
        // calculating prefix sum for each row of matrix
        for (int row = 0; row < N ; row++) {
            for (int col = 1; col < M; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }
        // calculate sum of each submatrix and check if is equal to target
        for (int colStart = 0; colStart < M; colStart++) {
            for (int colEnd = colStart; colEnd < M; colEnd++) {
                for (int rowStart = 0; rowStart < N; rowStart++) {
                    int sum = 0;
                    for (int rowEnd = rowStart; rowEnd < N; rowEnd++) {
                        sum += matrix[rowEnd][colEnd] - (colStart ? matrix[rowEnd][colStart - 1] : 0);
					    if(sum == target) ans++;
                    }
                }
            }
        }
        return ans;
    }
};
