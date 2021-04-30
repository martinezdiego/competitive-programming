// We are given two arrays A and B of words.  Each word is a string of lowercase letters.
// 
// Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".
// 
// Now say a word a from A is universal if for every b in B, b is a subset of a. 
// 
// Return a list of all universal words in A.  You can return the words in any order.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        vector<int> freqB(26, 0);
        for (const string & b : B) {
            vector<int> freq(26,0);
             for (char c : b) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) freqB[i] = max(freqB[i], freq[i]);
        }
        for (const string & a : A)
        {
            vector<int> freqA(26, 0);
            for (char c : a) {
                freqA[c - 'a']++;
            }
            
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (freqB[i]) {
                    valid &= freqB[i] <= freqA[i];
                }
            }
//             for (const string & b : B) {
//                 vector<int> freqB(26, 0);
//                 for (char c : b) {
//                     freqB[c - 'a']++;
//                 }
                
//                 bool ok = true;
//                 for (char c : b) {
//                     ok &= (freqB[c - 'a'] <= freqA[c - 'a']);
//                 }
//                 valid &= ok;
//             }
            if (valid) ans.push_back(a);
        }
        return ans;
    }
}; 
