// Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
// 
// Substrings that occur multiple times are counted the number of times they occur.
// 
// Input: s = "00110011"
// Output: 6

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int N = s.size();
        int ans = 0;
        groups.push_back(1);
        for (int i = 0; i + 1 < N; i++) {
            if (s[i] != s[i + 1]) {
                groups.push_back(1);
            }
            else {
                groups.back()++;
            }
        }
        int M = groups.size();
        for (int i = 0; i + 1 < M; i++) {
            ans += min(groups[i], groups[i + 1]);
        }
        return ans;
    }
}; 
