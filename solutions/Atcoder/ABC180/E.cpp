// traveling salesman problem in a 3D space
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1LL << 60;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;
    vector<long long> X(N), Y(N), Z(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
    
    auto dis = [&](int v, int nv) {
        long long add = abs(X[v] - X[nv]) + abs(Y[v] - Y[nv]) + max(0LL, Z[nv] - Z[v]);
        return add;  
    };
    
    vector<vector<long long>> dp(1<<N, vector<long long>(N+1, INF));
    
    // base case: no cities
    dp[1][0] = 0;
    
    for (int bit = 0; bit < (1 << N); ++bit) {
        for (int v = 0; v < N; ++v) {
            // if v is no set of bit
            if (!(bit & (1 << v))) 
                continue;
            for (int nv = 0; nv < N; ++nv) {
                // nv is set of bit
                if (bit & (1 << nv)) 
                    continue;
                // move to the resulting combination
                int nbit = bit | (1 << nv);
                // try to minimize resulting combination
                dp[nbit][nv] = min(dp[nbit][nv], dp[bit][v] + dis(v, nv));
            }
        }
    }
    
    long long ans = INF;
    
    for (int v = 0; v < N; ++v) {
        // find the min distance from the last combination to an origin v node
        ans = min(ans, dp[(1 << N) - 1][v] + dis(v, 0));
    }
    
    cout << ans << '\n';
    return 0;
}
