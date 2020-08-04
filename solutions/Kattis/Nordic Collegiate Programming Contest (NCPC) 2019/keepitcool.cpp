#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<pair<int,int>> slot(s);
    vector<int> ans(s, 0);
    int cnt = 0;
    for (int i = 0; i < s; i++) {
        cin >> slot[i].first;
        slot[i].second = i;
    }
    sort(slot.begin(), slot.end());
    for (int i = 0; i < s; i++) {
        if (n == 0) {
            cnt += slot[i].first;
            continue;
        }
        int x = min(d - slot[i].first, n);
        n -= x;
        if (n < 0)
            n = 0;
        ans[slot[i].second] = x;
    }
    if (cnt < m)
        cout << "impossible" << '\n';
    else {
        for (int i = 0; i < s; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
