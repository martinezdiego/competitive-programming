// Problema de Mochila sin limites con DP

#define MAX_N 1005
#define MAX_W 10005
#define INF 2000000000

int dp[MAX_W];
int gold[MAX_N];
int weight[MAX_N];
int N;

// Mochila sin limites top down
int unbounded_knapsack(int w)
{
    dp[0] = 0;
    for (int i = 1; i <= w; i++) {
        dp[i] = INF;
        for (int c = 0; c < N; c++) {
            if (i - W[c] >= 0)
                dp[i] = min(dp[i], dp[i - weight[c]] + gold[c]);
        }
    }
    return dp[w];
}

// Mochila sin limites buttom up
int unbounded_knapsack2(int w)
{
    if (w < 0)
        return INF;
    if (w == 0)
        return 0;
    int & ans = dp[w];
    if (ans != -1)
        return dp[w];
    ans = INF;
    for (int c = 0; c < N; c++) {
        ans = min(best, unbounded_knapsack2(w - weight[c]) + gold[c]);
    }
    return ans;
}

void init(int w)
{
    for (int i = 0; i <= w; i++)
        dp[i] = -1;
}