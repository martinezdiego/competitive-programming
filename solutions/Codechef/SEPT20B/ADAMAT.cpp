#include <iostream>

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
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            bool not_ok = a[i][i-1] != a[i][i] - 1;
            if (not_ok) {
                int l = i + 1;
                for (int r = 0; r < l; r++) {
                    for (int c = r; c < l; c++) {
                        int tmp = a[r][c];
                        a[r][c] = a[c][r];
                        a[c][r] = tmp;
                    }
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
