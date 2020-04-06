#include <bits/stdc++.h>

using namespace std;

#define MAX 102
 
int m[MAX][MAX];
int dp[MAX][MAX];
int h, w;

int solve(int r, int c)
{
    if (r > h)
        return 0;
    if (c < 1 or c > w)
        return 0;
    int & ans = dp[r][c];
    if (ans != -1)
        return ans;
    ans = max(max(solve(r + 1, c) + m[r][c], solve(r + 1, c - 1) + m[r][c]), solve(r + 1, c + 1) + m[r][c]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> h >> w;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                cin >> m[i][j];
        int ans = 0;
        memset(dp, -1, sizeof dp);
        for (int i = 1; i <= w; i++)
            ans = max(ans, solve(1, i));
        cout << ans << '\n';
    }
    return 0;
}