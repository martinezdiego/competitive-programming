class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int N = s.size();
        vector<int> v(N, 0);
        vector<int> pos;
        for (int i = 0; i < N; i++) {
            if (s[i] == c) pos.push_back(i);
        }
        for (int k = 0; k < pos.size(); k++) {
            for (int i = (k > 0 ? pos[k - 1] : 0); i <= pos[k]; i++) {
                if (k == 0) {
                    v[i] = pos[k] - i;
                }
                else {
                    v[i] = min(i - pos[k - 1], pos[k] - i);
                }
            }
        }
        for (int i = pos.back(); i < N; i++) {
            v[i] = (i - pos.back());
        }
        return v;
    }
};
