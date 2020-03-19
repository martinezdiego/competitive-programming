#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
#define MAXW 10005
#define MAXN 505

int W[MAXN], P[MAXN];
int dp[MAXW];
bool ready[MAXW];
int N;

int solve(int w)
{
    if (w < 0)
        return INF;
    if (w == 0)
        return 0;
    if (ready[w])
        return dp[w];
    int best = INF;
    for (int c = 0; c < N; c++) {
        best = min(best, solve(w - W[c]) + P[c]);
    }
    dp[w] = best;
    ready[w] = true;
    return dp[w];
}

void init(int w)
{
    for (int i = 0; i <= w; i++) {
        dp[i] = INF;
        ready[i] = false;
    }
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
        init(w);
        int ans = solve(w);
        if (ans == INF)
            cout << "This is impossible." << '\n';
        else
            cout << "The minimum amount of money in the piggy-bank is " << ans << ".\n";
    }
}