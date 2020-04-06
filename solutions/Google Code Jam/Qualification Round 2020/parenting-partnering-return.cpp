#include <bits/stdc++.h>

using namespace std;

using piii = pair<int,pair<int,int>>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        piii jamie = {0, {0, 0}};
        piii cammeron = {0, {0, 0}};
        priority_queue<piii,vector<piii>,greater<piii>> pq;
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            pq.push({x, {y, j}});
        }
        bool ok = true;
        string ans(n, '#');
        while(not pq.empty()) {
            auto top = pq.top();
            auto snd = top.second;
            pq.pop();
            if (jamie.second.first <= top.first) {
                jamie = top;
                ans[snd.second] = 'J';
            }
            else if (cammeron.second.first <= top.first) {
                cammeron = top;
                 ans[snd.second] = 'C';
            }
            else {
                ok = false;
                break;
            }
        }
        cout << (ok ? ans : "IMPOSSIBLE") << '\n';
    }
    return 0;
}