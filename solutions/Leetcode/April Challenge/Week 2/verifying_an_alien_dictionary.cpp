// In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
// 
// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int N = words.size();
        int M = order.size();
        for (int i = 1; i < N; i++) {
            if (!isSorted(words[i - 1], words[i], order)) return false;
        }
        return true;
    }
    
    bool isSorted(const string & a, const string & b, const string & order) {
        int N = a.size();
        int M = b.size();
        int i;
        for (i = 0; i < min(N, M); i++) {
            if (a[i] != b[i]) {
                if (getPos(a[i], order) < getPos(b[i], order)) return true;
                else return false;
            }
        }
        return i == N and getPos(a[i - 1], order) <= getPos(b[i - 1], order);
    }
    
    int getPos(char c, const string & order)
    {
        int N = order.size();
        for (int i = 0; i < N; i++) {
            if (order[i] == c) return i + 1;
        }
        return 0;
    }
}; 
