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
        
        int cnt_5 = 0;
        int cnt_10 = 0;
        bool ok = true;
        int a[n];
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 5)
                cnt_5++;
            if (a[i] == 10) {
                if (cnt_5)
                    cnt_5--;
                else {
                    ok = false;
                    break;
                }
                cnt_10++;
            }
            if (a[i] == 15) {
                if (cnt_10) {
                    cnt_10--;
                }
                else if (cnt_5 > 1) {
                    cnt_5 -= 2;
                }
                else {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
