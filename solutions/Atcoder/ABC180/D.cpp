#include <iostream>
#include <algorithm>

using namespace std;

long long solve()
{
    long long x,y,a,b;
    cin >> x >> y >> a >> b;
    long long ans = 1;
    long long mx = 0;
    for (long long i = 0; i <= 60; i++) {
        if (i)
            ans *= a;
        
        long long w = ans * x;
        
        if (w >= y)
            break;
        
        if (w < ((ans/a)*x))
            break;
        
        mx = max(mx, (i + (y-1-w)/b));
    }
    
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << solve() << '\n';
    return 0;
}
