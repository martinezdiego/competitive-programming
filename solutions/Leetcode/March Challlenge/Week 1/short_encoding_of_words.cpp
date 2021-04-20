/*
 *A valid encoding of an array of words is any reference string s and array of indices indices such that:

words.length == indices.length
The reference string s ends with the '#' character.
For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.
*/ 

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s;
        for (const string & word : words) s.insert(word);
        for (const string & word : words) {
            for (int i = 1; i < word.size(); i++) {
                s.erase(word.substr(i));
            }
        }
        int ans = 0;
        for (const string & word : s) ans += word.size() + 1;
        return ans;
    }
};
