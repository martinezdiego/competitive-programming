#include <iostream>

using namespace std;

#define MOD 998244353

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    int L[K], R[K];
    
    for (int i = 0; i < K; i++) {
        cin >> L[i] >> R[i];
    }
    
    long long dp[N] = { 0 };
    
    dp[0] = 1;
    dp[1] = -1;
    
    for (int i = 0; i < N; i++) {
        if (i) 
            dp[i] = (dp[i - 1] + dp[i])%MOD;
        for (int k = 0; k < K; k++) {
            int l = L[k];
            int r = R[k] + 1;
            if (i + l < N) dp[i + l] = (dp[i + l] + dp[i])%MOD;
            if (i + r < N) dp[i + r] = (dp[i + r] - dp[i] + MOD)%MOD;
        }
    }
    
    cout << dp[N - 1] << '\n';
    return 0;
}
