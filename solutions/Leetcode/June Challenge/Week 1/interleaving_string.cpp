class Solution {
    int dp[105][105][205];
    
    bool check(int p1, int p2, int p3, const string & s1, const string & s2, const string & s3)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        if (p3 == len3) {
            return p1 == len1 && p2 == len2;
        }
        
        if (dp[p1][p2][p3] != -1) return dp[p1][p2][p3];
        
        if (p1 == len1) {
            return dp[p1][p2][p3] = (s2[p2] == s3[p3] ? check(p1, p2 + 1, p3 + 1, s1, s2, s3) : false);
        }
        
        if (p2 == len2) {
            return dp[p1][p2][p3] = (s1[p1] == s3[p3] ? check(p1 + 1, p2, p3 + 1, s1, s2, s3) : false);
        }
        
        bool ans = false;
        
        if (s1[p1] == s3[p3]) {
            ans = check(p1 + 1, p2, p3 + 1, s1, s2, s3);
        }
        
        if (s2[p2] == s3[p3]) {
            ans |= check(p1, p2 + 1, p3 + 1, s1, s2, s3);
        }
        
        return dp[p1][p2][p3] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3) return false;
        memset(dp, -1, sizeof dp);
        return check(0, 0, 0, s1, s2, s3);
    }
}; 
