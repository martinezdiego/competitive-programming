#include <iostream>

using namespace std;

#define INF (1LL << 62)

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    long long x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    long long mx1, mn1, mx2, mn2;
    mx1 = mx2 = -INF;
    mn1 = mn2 = INF;
    for (int i = 0; i < n; i++) {
        mx1 = max(mx1, x[i] + y[i]);
        mn1 = min(mn1, x[i] + y[i]);
        mx2 = max(mx2, x[i] - y[i]);
        mn2 = min(mn2, x[i] - y[i]);
    }
    cout << max(mx1 - mn1, mx2 - mn2) << '\n';
    return 0;
}
