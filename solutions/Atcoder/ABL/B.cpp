#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    
    bool not_ok = C > B and D > B;
    not_ok |= C < A and D < A;
    
    cout << (not_ok ? "No" : "Yes") << '\n';
    
    return 0;
}
