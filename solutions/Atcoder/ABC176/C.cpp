#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n];
    b[0] = a[0];
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        b[i] =  max(a[i], b[i - 1]);
        ans += b[i] - a[i];
    }
    cout << ans << '\n';
    return 0;
}
