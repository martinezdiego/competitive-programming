#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000
#define MAX_N 1002

int oxigen[MAX_N]; 
int nitrogen[MAX_N];
int weight[MAX_N];
int dp[MAX_N][22][80];
int seen[MAX_N][22][80];
int tt;

int solve(int i, int ox, int ni)
{
    if (ox <= 0 and ni <= 0)
        return 0;
    if (i < 1)
        return INF;
    int & ans = dp[i][ox][ni];
    if (seen[i][ox][ni] == tt)
        return ans;
    seen[i][ox][ni] = tt;
    ans = min(  solve(i - 1, ox, ni), 
                solve(i - 1, max(ox - oxigen[i], 0), max(ni - nitrogen[i], 0)) + weight[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (tt = 1; tt <= t; tt++)
    {
        int n, to, tn;
        cin >> to >> tn >> n;
        for (int i = 1; i <= n; i++)
            cin >> oxigen[i] >> nitrogen[i] >> weight[i];
        cout << solve(n, to, tn) << '\n';
    }
    return 0;
}