// Given a string, your task is to count how many palindromic substrings in this string.
// 
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        int dp[N][N];
        memset(dp, 0, sizeof dp);
        int ans = 0;
        // Base case: single letter substrings
        for (int i = 0; i < N; i++) {
            dp[i][i] = 1;
            ans++;
            
        }
        // Base case: double letter substrings
        for (int i = 0; i + 1 < N; i++) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            ans += dp[i][i + 1];
        }
         // All other cases: substrings of length 3 to n
        for (int len = 3; len <= N; len++) {
            for (int i = 0, j = i + len - 1; j < N; i++, j++) {
                dp[i][j] = (dp[i + 1][j - 1] and s[i] == s[j]);
                ans += dp[i][j];
            }
        }
        return ans;
    }
}; 
