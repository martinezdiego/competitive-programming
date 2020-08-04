#include <bits/stdc++.h>

using namespace std;

long long ans;

void check(long long x[], long long y[])
{
    long long w1 = x[0] + x[1] + x[2];
    long long h1 = max(max(y[0],y[1]),y[2]);
    long long area = w1 * h1;
    if (y[0] >= y[1]) {
        long long w2 = max(x[0] + x[1], x[2]);
        long long h2 = y[0] + y[2];
        area = min(area, w2 * h2);
    }
    ans = min(ans, area);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long a[3], b[3];
        for (int i = 0; i < 3; i++) {
            cin >> a[i] >> b[i];
        }
        ans = numeric_limits<long long>::max();
        int p[] = { 0, 1, 2 };
        do
        {
            for (int k = 0; k < (1 << 3); k++) {
                long long x[3], y[3];
                for (int i = 0; i < 3; i++) {
                    x[i] = a[p[i]];
                    y[i] = b[p[i]];
                }
                if (k & 1) swap(x[0], y[0]);
                if (k & 2) swap(x[1], y[1]);
                if (k & 4) swap(x[2], y[2]);
                check(x, y);
            }
        } while (next_permutation(p, p + 3));
        
        cout << ans << '\n';
    }
}
