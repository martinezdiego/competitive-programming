#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10005

long long dp[MAX_N];
long long gold[MAX_N];
int N;

long long solve(int i)
{
	if (i < 0) 
		return 0;
	long long & ans = dp[i];
	if (ans != -1) 
		return ans;
	ans = max(solve(i - 1), solve(i - 2) + gold[i]);
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(dp, -1, sizeof dp);
        cin >> N;
        for (int j = 0; j < N; j++)
            cin >> gold[j];
        cout << "Case " << i << ": " << solve(N - 1) << '\n';
    }
    return 0;
}