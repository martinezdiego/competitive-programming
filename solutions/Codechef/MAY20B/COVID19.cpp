#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int mn = 10;
        int mx = 1;
        for (int i = 0; i < n; i++) {
            int l = i - 1;
            int r = i + 1;
            int l_cnt = 0;
            int r_cnt = 0;
            while (l >= 0) {
                if (a[l + 1] - a[l] <= 2) {
                    l_cnt++;
                    l--;
                }
                else 
                    break;
            }
            while (r < n) {
                if (a[r] - a[r - 1] <= 2) {
                    r_cnt++;
                    r++;
                }
                else
                    break;
            }
            mn = min(mn, l_cnt + r_cnt + 1);
            mx = max(mx, l_cnt + r_cnt + 1);
        }
        cout << mn << ' ' << mx << '\n';
    }
    return 0;
}