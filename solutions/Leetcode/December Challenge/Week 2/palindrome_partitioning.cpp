class Solution {
private:
    vector<vector<string> > result;
    bool dp[17][17];
    
    bool is_palindrome(const string & s, int l, int r) 
    {
        while (l < r) {
            if (s[l++] != s[r--]) 
                return false;
        }
        return true;
    }
    
    // backtracking + DP approach
    void dfs(const string & s, int start, vector<string> & cur_list)
    {
        if (start >= s.size()) {
            result.push_back(cur_list);
            return;
        }
        
        for (int end = start; end < s.size(); end++) {
            // O(N)
            //if (is_palindrome(s, start, end)) {
            // O(1)
            if (s[start] == s[end] and (end - start <= 2 or dp[start + 1][end - 1])) {
                dp[start][end] = true;
                cur_list.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, cur_list);
                cur_list.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur_list;
        dfs(s, 0, cur_list);
        return result;
    }
};
