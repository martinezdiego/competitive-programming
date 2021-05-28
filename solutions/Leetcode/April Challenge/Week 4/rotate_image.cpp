// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// 
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<vector<int> > trans(M, vector<int>(N, 0));
        int row = 0, col = 0;
        for (int i = 0; i < M; i++) {
            for (int j = N-1; j >= 0; j--) {
                trans[row][col++] = matrix[j][i];
            }
            row++;
            col = 0;
        }
        matrix = trans;
    }
}; 
