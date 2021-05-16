// You are given an array of binary strings strs and two integers m and n.
// 
// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// 
// A set x is a subset of a set y if all elements of x are also elements of y.


class Solution {
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101] = {0};                    

        for (auto &str : strs) {
          int n0 = 0, n1 = 0;

          for (auto &ch : str)
            if(ch == '0') n0++;
            else n1++;

          for (int i = m; i >= n0; i--)
            for (int j = n; j >= n1; j--)
              dp[i][j] = max(dp[i][j], dp[i - n0][j - n1] + 1);
        }

        return dp[m][n];
    }
}; 
