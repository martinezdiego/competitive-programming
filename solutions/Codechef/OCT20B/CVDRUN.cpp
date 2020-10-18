#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a%b);
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        bool ok = abs(x- y)%gcd(n, k) == 0;
//         for (int i = 0; i < 1000; i++) {
//             if (x == y) {
//                 ok = true;
//                 break;
//             }
//             x += k;
//             x %= n;
//         }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
