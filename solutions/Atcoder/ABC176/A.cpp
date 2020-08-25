#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, t;
    cin >> n >> x >> t;
    int p = n/x;
    int r = n%x;
    cout << (p * t + (r ? max(r/x, 1) * t : 0)) << '\n';
    return 0;
}
