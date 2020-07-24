#include <bits/stdc++.h>

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

        int amount = 0;

        while (n--) {
            int x;
            cin >> x;
            if (k < x)
                amount += x - k;
        }
        
        cout << amount << '\n';
    }
}
