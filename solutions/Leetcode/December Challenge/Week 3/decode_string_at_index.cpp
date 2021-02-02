class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long len = 0;
        int N = S.size();
        for (char c : S) {
            if (isdigit(c))
                len *= c -'0';
            else
                len++;
        }
        for (int i = N-1; i >= 0; i--) {
            K %= len;
            if (K == 0 and isalpha(S[i]))
                return S.substr(i, 1);
            
            if (isdigit(S[i])) len /= S[i] - '0';
            else len--;
        }
        return "";
    }
};
