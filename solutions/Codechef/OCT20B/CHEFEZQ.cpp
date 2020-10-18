#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        
        long long q[n + 1];
        long long ans = 0;
        bool found = false;
        
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }
        
        q[n + 1] = 0;
        
        for (int i = 0; i + 1 <= n; i++) {
            ans = i + 1;
            q[i] -= k;
            if (q[i] < 0) {
                found = true;
                break;
            }
            q[i + 1] += q[i];
        }
        
        if (!found) {
            ans += q[n - 1]/k + 1;
        }
        
        cout << ans << '\n';
    }
}
