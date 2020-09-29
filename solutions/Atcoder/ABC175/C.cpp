#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, k, d;
    cin >> x >> k >> d;
    if (x < 0)
        x = -x;
    long long a = x/d;
    if (k < a) {
        cout << x  - k*d << '\n';
    }
    else {
        long long r = k - a;
        if (r%2 == 0)
            cout << x - a*d << '\n';
        else
            cout << abs(x - a*d - d) << '\n';
    }
    return 0;
}
