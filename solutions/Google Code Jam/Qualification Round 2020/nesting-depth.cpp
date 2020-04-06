#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        string s;
        cin >> s;
        int cur_depth = 0;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            // cout << s[i] << ' ' << cur_depth << endl;
            if ((s[i] - '0') > cur_depth) {
                int d = (s[i] - '0') - cur_depth;
                cout << string(d, '(');
                cur_depth += d;
            }
            else if ((s[i] - '0') < cur_depth) {
                int d = cur_depth - (s[i] - '0');
                cout << string(d, ')');
                cur_depth -= d;
                
            }
            cout << s[i];
        }
        cout << string(cur_depth, ')') << '\n';
    }
    return 0;
}