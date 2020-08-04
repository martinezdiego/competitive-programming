#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> trees(n);
    for (auto & p : trees) {
        cin >> p.first >> p.second;
    }
    sort(trees.begin(), trees.end());
    int ans = 0;
    unordered_map<int,int> dp;
    for (auto & p : trees) {
        dp[p.first + p.second] = max(dp[p.first + p.second], dp[p.first] + p.second);
        dp[p.first] = max(dp[p.first], dp[p.first - p.second] + p.second);
        ans = max(ans, max(dp[p.first], dp[p.first + p.second]));
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}
