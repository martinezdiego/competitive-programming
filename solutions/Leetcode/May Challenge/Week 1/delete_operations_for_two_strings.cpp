// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// 
// In one step, you can delete exactly one character in either string.

class Solution {
    vector<vector<int> > dp;
    int f(int i, int j, string & word1, string & word2)
    {
        if (i < 0) 
            return 0;
        if (j < 0)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
            
        if (word1[i] == word2[j]) {
            ans = 1 + f(i - 1, j - 1, word1, word2);
        }
        else {
            ans = max(f(i - 1, j, word1, word2), f(i, j - 1, word1, word2));      
        }
        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        dp.assign(N, vector<int>(M, - 1));
        return N + M - 2 * f(N - 1, M - 1, word1, word2);
    }
}; 
