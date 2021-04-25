class Solution {
    void bruteforce(string & s, int k, set<string> & comb)
    {
        if (s.size() == k) {
            comb.insert(s);
            return;
        }
        
        s.push_back('0');
        bruteforce(s, k, comb);
        s.pop_back();
        
        s.push_back('1');
        bruteforce(s, k, comb);
        s.pop_back();
    }
public:
    bool hasAllCodes(string s, int k) {
        set<string> comb;
        string ss;
        int N = s.size();
        // bruteforce(ss, k, comb);
        for (int i = 0; i + k <= N; i++) {
            ss = s.substr(i, k);
            // comb.erase(ss);
            comb.insert(ss);
        }
        return comb.size() == (1 << k);
    }
}; 
