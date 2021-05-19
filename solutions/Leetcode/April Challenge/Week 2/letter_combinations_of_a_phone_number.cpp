// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// 
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

class Solution {
    void bruteforce(int i, string & s, string & digits, vector<string> & ans, vector<string> & numpad)
    {
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }
        
        int num = digits[i] - '0';
        int N = numpad[num].size();
        
        for (int j = 0; j < N; j++) {
            s.push_back(numpad[num][j]);
            bruteforce(i + 1, s, digits, ans, numpad);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int N = digits.size();
        if (N == 0) return ans;
        vector<string> numpad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur;
        bruteforce(0, cur, digits, ans, numpad);
        return ans;
    }
}; 
