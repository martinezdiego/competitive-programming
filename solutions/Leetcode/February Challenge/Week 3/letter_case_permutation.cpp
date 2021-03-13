class Solution {
    vector<string> comb;
    
    void bruteforce(int N, string & s, vector<pair<char, int> > & letters, int i)
    {
        if (i == N) {
            comb.push_back(s);
            return;
        }
        
        s[letters[i].second] = toupper(letters[i].first);
        bruteforce(N, s, letters, i + 1);
        
        s[letters[i].second] = tolower(letters[i].first);
        bruteforce(N, s, letters, i + 1);
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<pair<char, int> > letters;
        for (int i = 0; i < S.size(); i++) {
            if (isalpha(S[i])) letters.push_back({S[i], i});
        }
        bruteforce(letters.size(), S, letters, 0);
        return comb;    
    }
}; 
