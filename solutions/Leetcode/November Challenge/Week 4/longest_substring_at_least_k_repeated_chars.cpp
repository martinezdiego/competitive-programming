class Solution {
private:
    int max_unique_letters(const string & s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        int unique = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) unique++;
        }
        return unique;
    }
public:
    int longestSubstring(string s, int k) {
        int max_unique = max_unique_letters(s);
        int N = s.size();
        int ans = 0;
        for (int cur_unique = 1; cur_unique <= max_unique; cur_unique++) {
            int unique = 0;
            int count_at_least_k = 0;
            int cnt[26] = {0};
            int start = 0, end = 0;
            while (end < N)   
            {
                if (unique <= cur_unique) {
                    if (cnt[s[end] - 'a'] == 0) unique++;
                    cnt[s[end] - 'a']++;
                    if (cnt[s[end] - 'a'] == k) count_at_least_k++;
                    end++;
                }
                else {
                    if (cnt[s[start] - 'a'] == k) count_at_least_k--;
                    cnt[s[start] - 'a']--;
                    if (cnt[s[start] - 'a'] == 0) unique--;
                    start++;
                }
                if (unique == cur_unique && unique == count_at_least_k)
                    ans = max(ans, end - start);
            }
        }
        return ans;
    }
};
