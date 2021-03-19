class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        for (int i = 0; i < N; i++)
        {
            int low = 0;
            int high = M - 1;
            while (low < high)
            {
                int mid = low + (high - low)/2;
                if (matrix[i][mid] < target) low = mid + 1;
                else high = mid;
            }
            if (matrix[i][low] == target) return true;
        }
        return false;
    }
}; 
