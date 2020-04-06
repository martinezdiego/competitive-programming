#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        int ans = 0;
        for (int i = n; i > 0; i--)
        {
            int top = pq.top() - (n - i);
            pq.pop();
            top = max(top , 0);
            ans += top;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}