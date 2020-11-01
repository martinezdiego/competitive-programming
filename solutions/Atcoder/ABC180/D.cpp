#include <iostream>
#include <algorithm>

using namespace std;

long long Y, A, B;

long long solve(long long X)
{
    if (X == Y)
        return 0;
    if (X > Y)
        return -1;
    
    long long l = solve(X * A) + 1;
    long long r = solve(X + B) + 1;
    
    return max(r, l); 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long X;
    cin >> X >> Y >> A >> B;
    cout << solve(X);
    return 0;
}
