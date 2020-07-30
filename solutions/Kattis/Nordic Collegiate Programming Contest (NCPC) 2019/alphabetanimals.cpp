#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string prev;
    int n;
    cin >> prev >> n;
    vector<int> start(26,0);
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        start[words[i].front() - 'a']++;
    }
    if (start[prev.back() - 'a'] == 0) {
        cout << "?\n";
        return 0;
    }
    string ans;
    for (int i = 0; i < n; i++) {
        if (words[i].front() != prev.back()) {
            continue;
        }
        if (ans == "") {
            ans = words[i];
        }
        if (start[words[i].back() - 'a'] == 0 or (start[words[i].back() - 'a'] == 1 and words[i].front() == words[i].back())) {
            cout << words[i] << "!\n";
            return 0;
        }
    }
    cout << ans << '\n';
}