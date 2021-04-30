// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
// 
// Return true if and only if we can do this so that the resulting number is a power of two.

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int pwr = 1;
        unordered_map<int, int> freq;
        while (N) {
            freq[N%10]++;
            N /= 10;
        }
        while (pwr <= 1000000000)
        {
            int cur = pwr;
            unordered_map<int, int> freq2;
            while (cur) {
                freq2[cur%10]++;
                cur /= 10;
            }
            bool ok = true;
            for (const auto & p : freq2) {
                if (freq.find(p.first) == freq.end() or freq[p.first] != p.second) {
                    ok = false;
                    break;
                }
            }
            if (ok and freq2.size () == freq.size()) {
                // cout << pwr << endl;
                return true;
            }
            pwr *= 2;
        }
        return false;
    }
};
