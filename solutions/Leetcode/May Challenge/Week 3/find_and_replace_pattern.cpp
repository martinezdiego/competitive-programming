class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string & word : words) {
            if (match(word, pattern)) ans.push_back(word);
        } 
        return ans;
    }
    
    bool match(const string & word, const string & pattern)
    {
        vector<int> word_to_pattern(26, -1);
        vector<int> pattern_to_word(26, -1);
        int N = word.size();
        for (int i = 0; i < N; i++) {
            if (word_to_pattern[word[i] - 'a'] == -1) {
                word_to_pattern[word[i] - 'a'] = pattern[i] - 'a';
            }
            if (pattern_to_word[pattern[i] - 'a'] == -1) {
                pattern_to_word[pattern[i] - 'a'] = word[i] - 'a';
            }
            if (pattern_to_word[pattern[i] - 'a'] != word[i] - 'a' || word_to_pattern[word[i] - 'a'] != pattern[i] - 'a') {
                return false;
            }
        }
        return true;
    }
}; 
