// Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".

class Solution {
    int m[1001][26];
public:
    int maxProduct(vector<string>& words) {
        int N = words.size();
        size_t ans = 0;
        // memset(m, 0, sizeof m);
        vector<int> mask(N);
        for (int i = 0; i < N; i++) {
            for (char c : words[i]) {
                // m[i][c - 'a'] = 1;
                mask[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; j++) {
                // if (check(i, j)) {
                //     ans = max(ans, words[i].size() * words[j].size());
                // }
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, words[i].size() * words[j].size());
                }
            }
        }
        return ans;
    }
    
    bool check(int i, int j)
    {
        for (int c = 0; c < 26; c++) {
            if (m[i][c] && m[j][c]) return false;
        }
        return true;
    }
}; 
