 
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char prev = '*';
        map<char, int> m = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int N = s.size();
        for (int i = N - 1; i >= 0; i--) {
            ans += m[s[i]];
            if (prev != '*') {
                if (m[prev] > m[s[i]])
                    ans -= m[s[i]] * 2;
            }
            prev = s[i];
        }
        return ans;
    }
};
