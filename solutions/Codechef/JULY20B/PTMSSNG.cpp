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
        int x = 0, y = 0;
        for (int i = 0; i < 4*n - 1; i++)
        {
            int xi, yi;
            cin >> xi >> yi;
            x^=xi;
            y^=yi;
        }
        cout << x << ' ' << y << '\n';
    }
}
