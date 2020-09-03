#include <iostream>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int mx = 0;
    for (int i = 0; i + m <= n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (t[j] == s[i + j]) cnt++;
        }
        mx = max(cnt, mx);
    }
    cout << m - mx << '\n';
    return 0;
}
