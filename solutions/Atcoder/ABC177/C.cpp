#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long suff = 0, ans = 0;
    for (int i = n-1; i >= 0; i--) {
        ans = ans + (a[i] * suff);
        suff += a[i];
        ans %= MOD;
        suff %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
