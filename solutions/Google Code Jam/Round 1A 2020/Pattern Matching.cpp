#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        string pattern[n];
        string pref[n];
        string suff[n];
        for (int i = 0; i < n; i++)
            cin >> pattern[i];
        int longest_prefix = 0;
        int longest_suffix = 0;
        for (int i = 0; i < n; i++) {
            while (pattern[i].front() != '*') {
                pref[i].push_back(pattern[i].front());
                pattern[i].erase(pattern[i].begin());
            }
            while (pattern[i].back() != '*') {
                suff[i] = pattern[i].back() + suff[i];
                pattern[i].pop_back();
            }
            if (pref[i].size() > pref[longest_prefix].size()) 
                longest_prefix = i;
            if (suff[i].size() > suff[longest_suffix].size()) 
                longest_suffix = i;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            string sub = pref[longest_prefix].substr(0, pref[i].size());
            if (sub != pref[i]) {
                ok = false;
                break;
            }
        }
        if (not ok) {
            cout << "*\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            string sub = suff[longest_suffix].substr(suff[longest_suffix].size() - suff[i].size());
            if (sub != suff[i]) {
                ok = false;
                break;
            }
        }
        if (not ok) {
            cout << "*\n";
            continue;
        }
        cout << pref[longest_prefix];
        for (int i = 0; i < n; i++) {
            for (auto c : pattern[i])
                if (c != '*')
                    cout << c;
        }
        cout << suff[longest_suffix] << '\n';
    }
}