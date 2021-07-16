// Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
// 
// Return list of lists of the suggested products after each character of searchWord is typed. 

// Example 1:
// 
// Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
// Output: [
// ["mobile","moneypot","monitor"],
// ["mobile","moneypot","monitor"],
// ["mouse","mousepad"],
// ["mouse","mousepad"],
// ["mouse","mousepad"]
// ]
// Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
// After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
// After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

class Trie
{
public:
        Trie() {
            children.assign(26, nullptr);
            isWord = false;
        }
        
        void insert(const string & s) {
            Trie* cur = this;
            for (char c : s) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new Trie();
                }
                cur = cur->children[c - 'a'];
            }
            cur->isWord = true;
        }
    
        vector<string> getWordsStartingWith(string & prefix)
        {
            Trie* cur = this;
            vector<string> result;
            for (char c : prefix) {
                if (!cur->children[c - 'a'])
                    return result;
                cur = cur->children[c - 'a'];
            }
            dfs(cur, prefix, result);
            return result;
        }
private:
        vector<Trie*> children;
        bool isWord;
    
        void dfs(Trie* cur, string & word, vector<string> & result)
        {
            if (result.size() == 3)
                return;
            
            if (cur->isWord)
                result.push_back(word);
            
            for (char c = 'a'; c <= 'z'; c++) {
                if (cur->children[c - 'a']) {
                    word.push_back(c);
                    dfs(cur->children[c - 'a'], word, result);
                    word.pop_back();
                }
            }
        }
};

class Solution {
public:
    // bsearch solution
    vector<vector<string>> suggestedProductsBS(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string pref;
        int start = 0;
        vector<vector<string> > ans;
        int N = products.size();
        for (char c : searchWord)
        {
            pref.push_back(c);
            int pos = lower_bound(products.begin() + start, products.end(), pref) - products.begin();
            ans.push_back({});
            for (int i = pos; i < min(pos + 3, N) && products[i].substr(0, pref.size()) == pref; i++) {
                ans.back().push_back(products[i]);
            }
            start = pos;
        }
        return ans;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        Trie trie;
        vector<vector<string> > ans;
        string pref;
        for (const string & product : products) {
            trie.insert(product);
        }
        for (char c : searchWord) {
            pref.push_back(c);
            ans.push_back(trie.getWordsStartingWith(pref));
        }
        return ans;
    }
};
