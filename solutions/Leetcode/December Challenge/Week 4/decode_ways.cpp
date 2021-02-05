class Solution {
private:
    int memo[105];
    
    int helper(const string & s, int k) {
        if (k == 0) return 1;
        int len = s.size();
        int start = len - k; 
        if (s[start] == '0') return 0;
        if (memo[k] != -1) return memo[k];
        int result = helper(s, k - 1);
        if (k >= 2) {
            string sub = s.substr(start, 2);
            int num = stoi(sub, nullptr, 10);
            if (num <= 26)
                result += helper(s, k - 2);
        }
        memo[k] = result;
        return result;
    }
public:
    int numDecodings(string s) {
        memset(memo, -1, sizeof memo);
        return helper(s, s.size());
    }
};
