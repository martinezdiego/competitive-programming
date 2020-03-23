#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2005

int values[MAX_N];
int dp[MAX_N][MAX_N];
int N;

int solve(int l, int r)
{
    int d = (l - 1) + (N - r) + 1;
    if (l > r)
        return 0;
    if (r < 1)
        return 0;
    int & ans = dp[l][r];
    if (ans != -1)
        return ans;
    ans = max(solve(l + 1, r) + values[l] * d, solve(l, r - 1) + values[r] * d);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> values[i];
    memset(dp, -1, sizeof dp);
    cout << solve(1, N) << '\n';
}