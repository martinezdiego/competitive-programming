// Design a special dictionary with some words that searchs the words in it by a prefix and a suffix.
// 
// Implement the WordFilter class:
// 
// WordFilter(string[] words) Initializes the object with the words in the dictionary.
// f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.

// Trie + Set intersection approach
class Trie
{
public:
    vector<Trie*> t;
    vector<int> index;
    
    Trie() {
        t.assign(26, nullptr);
    }
    
     ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (t[i]) {
                delete t[i];
            }
        }
    }
    
    void insert(const string & word, int i)
    {
        Trie* cur = this;
        for (char c : word) {
            if (cur->t[c - 'a'] == nullptr) {
                cur->t[c - 'a'] = new Trie();
            }
            cur = cur->t[c - 'a'];
            cur->index.push_back(i);
        }
    }
    
    vector<int> startsWith(const string & word)
    {
        Trie* cur = this;
        for (char c : word) {
            if (cur->t[c - 'a'] == nullptr) {
                return vector<int>();
            }
            cur = cur->t[c - 'a'];
        }
        return cur->index;
    }
};

class WordFilter {
    Trie prefix;
    Trie suffix;
public:
    WordFilter(vector<string>& words) {
        int N = words.size();
        for (int i = 0; i < N; i++) {
            prefix.insert(words[i], i);
            reverse(words[i].begin(), words[i].end());
            suffix.insert(words[i], i);
        }
        
    }
    
    int f(string pref, string suff) {
        reverse(suff.begin(), suff.end());
        vector<int> pref_index = prefix.startsWith(pref);
        vector<int> suff_index = suffix.startsWith(suff);
        int i = pref_index.size() - 1;
        int j = suff_index.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pref_index[i] == suff_index[j]) return pref_index[i];
            else if (pref_index[i] > suff_index[j]) i--;
            else j--;
        }
        return -1;
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */ 
