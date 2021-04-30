// Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
// 
// For a given query word, the spell checker handles two categories of spelling mistakes:
// 
// Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
// Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
// Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
// Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
// Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
// Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
// Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
// Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
// In addition, the spell checker operates under the following precedence rules:
// 
// When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
// When the query matches a word up to capitlization, you should return the first such match in the wordlist.
// When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
// If the query has no matches in the wordlist, you should return the empty string.
// Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

// Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
// Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

class Solution {
private:
    set<string> words;
    map<string, string> cap;
    map<string, string> vowel_map;
    
    string replacevowels(const string & word)
    {
        string ans;
        for (char c : word) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ans.push_back('*');
            else ans.push_back(c);
        }
        return ans;
    }
    
    string solve(const string & query)
    {
        if (words.find(query) != words.end())
            return query;
        
        string lowercase;
        for (char c : query) lowercase.push_back(tolower(c));
        if (cap.find(lowercase) != cap.end()) {
            return cap[lowercase]; 
        }
        
        string vowel = replacevowels(lowercase);
        if (vowel_map.find(vowel) != vowel_map.end()) {
            return vowel_map[vowel]; 
        }
        
        return "";
    }
    
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (const string & word : wordlist)
        {
            words.insert(word);
            string lowercase;
            for (char c : word) lowercase.push_back(tolower(c));
            if (cap.find(lowercase) == cap.end()) {
                cap[lowercase] = word; 
            }
            string vowel = replacevowels(lowercase);
            if (vowel_map.find(vowel) == vowel_map.end()) {
                vowel_map[vowel] = word; 
            }
        }
        
        vector<string> ans;
        for (const string & query : queries) {
            ans.push_back(solve(query));
        }
        return ans;
    }
};
