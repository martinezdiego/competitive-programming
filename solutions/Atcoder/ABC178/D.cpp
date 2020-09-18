#include <iostream>

using namespace std;

#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int S;
    cin >> S;
    int dp[2005];
    dp[0] = 1;
    dp[1] = dp[2] = 0;
    for (int i = 3; i <= S; i++) {
        dp[i] = (dp[i-1] + dp[i-3])%MOD;
    }
    cout << dp[S]%MOD << '\n';
    return 0;
}
