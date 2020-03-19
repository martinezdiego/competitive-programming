#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
#define MAXW 10005
#define MAXN 505

int W[MAXN], P[MAXN];
int dp[MAXW];
int N;

int solve(int w)
{
    dp[0] = 0;
    for (int i = 1; i <= w; i++) {
        dp[i] = INF;
        for (int c = 0; c < N; c++) {
            if (i - W[c] >= 0)
                dp[i] = min(dp[i], dp[i - W[c]] + P[c]);
        }
    }
    return dp[w];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int empty, full;
        cin >> empty >> full >> N;
        for (int i = 0; i < N; i++)
            cin >> P[i] >> W[i];
        int w = full - empty;
        int ans = solve(w);
        if (ans == INF)
            cout << "This is impossible." << '\n';
        else
            cout << "The minimum amount of money in the piggy-bank is " << ans << ".\n";
    }
}