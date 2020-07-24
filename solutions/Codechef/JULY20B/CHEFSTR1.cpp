#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n, a , b;
        cin >> n >> a;
        n--;
        long long ans = 0;
        while (n--) {
            cin >> b;
            ans += abs(a - b) - 1;
            a = b;
        }
        cout << ans << '\n';
    }
}
