#include <bits/stdc++.h>

using namespace std;

int main() 
    {
    int t;
    cin >> t;
    while (t--)
    {
        string s, p;
        cin >> s >> p;

        vector<int> a(26, 0);
        bool inserted = false;

        for (auto c : s) a[c - 'a']++;
        for (auto c : p) a[c - 'a']--;

        int offset = 1;

        for (int i = 0; i + 1 < (int)p.size(); i++) {
            if (p[i] == p[i + 1]) continue;
            if (p[i + 1] < p[i]) offset = 0; 
            break;
        }

        int pos = p[0] - 'a' + offset;

        for (int i = 0; i < pos; i++) {
            while (a[i]) {
                cout << (char)(i + 'a');
                a[i]--;
            }
        }
        cout << p;
        for (int i = pos; i < 26; i++) {
            while (a[i]) {
                cout << (char)(i + 'a');
                a[i]--;
            }
        }
        cout << '\n';
    }
    return 0;
}
