// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
// 
// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
// 
// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
// 
// Note: You cannot rotate an envelope.

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a,const vector<int> &b){
                 return (a[0]==b[0] ? a[1]<b[1] : a[0]<b[0]);
             });
        int N = envelopes.size();
        int ans = 1;
        vector<int> dp(N + 1, 1);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0]<envelopes[i][0] and envelopes[j][1]<envelopes[i][1]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        ans = max(ans, dp[i]);
                    }
                }
            }
        }
        return ans;
    }
}; 
