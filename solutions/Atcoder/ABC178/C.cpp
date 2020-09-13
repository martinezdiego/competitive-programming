#include <iostream>

using namespace std;

#define MOD 1000000007

int main()
{
    int n;
    cin >> n;
    if (n < 2) {
        cout << 0 << '\n';
        return 0;
    }
    long long x, y, z;
    x = y = z = 1;
    for (int i = 1; i <= n; i++) {
        x = (x * 10)%MOD;
        y = (y * 9)%MOD;
        z = (z * 8)%MOD;
    }
    long long ans = x + z;
    ans -=  (2 * y)%MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
