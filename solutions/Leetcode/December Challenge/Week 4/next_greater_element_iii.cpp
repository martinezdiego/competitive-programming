class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (next_permutation(s.begin(), s.end())) {
            long long val = stoll(s, nullptr, 10);
            if (val > INT_MAX) return -1;
            return (int) val;
        }
        return -1;
    }
};
