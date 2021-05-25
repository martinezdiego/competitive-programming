// Given a triangle array, return the minimum path sum from top to bottom.
// 
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 
class Solution {
    vector<vector<int> > dp;
    
    int f(int row, int i, vector<vector<int>> & triangle)
    {
        if (row == triangle.size()) {
            return 0;
        }
        
        if (i == triangle[row].size()) {
            return 0;
        }
        
        if (dp[row][i] != -1) return dp[row][i];
        
        int ans = triangle[row][i];
        
        ans += min(f(row + 1, i, triangle), f(row + 1, i + 1, triangle));
        
        return dp[row][i] = ans;
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        dp.assign(N + 1, vector<int>(N + 1, -1));
        return f(0, 0, triangle);
    }
};
