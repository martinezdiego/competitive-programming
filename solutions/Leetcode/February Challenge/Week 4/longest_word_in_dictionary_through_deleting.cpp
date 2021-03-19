class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        int N = s.size();
        int D = d.size();
        string ans = "";
        for (const string & word : d) {
            int len = word.size();
            int match = 0;
            for (int i = 0; i < N; i++) {
                if (s[i] == word[match]) match++;
            }
            if (match == len) {
                if (len > ans.size()) ans = word;
            } 
        }
        return ans;
    }
}; 
