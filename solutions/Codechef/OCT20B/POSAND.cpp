#include <algorithm>
#include <iostream>

using namespace std;

void solve(int n)
{
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }

    if((n & -n) == n) {
        cout << -1 << '\n';
        return;
    }
    
    cout << 2 << ' ' << 3 << ' ' << 1 << ' ';
    for (int i = 2; (1 << i) <= n; i++) {
        cout << ((1 << i) + 1) << ' ' << (1 << i) << ' ';
        for (int x = (1 << i); x <= min(n, (2 << i) - 1); x++) {
            if(x > (1 << i) + 1) 
                cout << x << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
