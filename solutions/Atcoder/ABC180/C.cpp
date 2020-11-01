#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long N;
    cin >> N;
    set<long long> divs;
    for (long long i = 1; i*i <= N; i++) {
        if (N%i == 0) {
            divs.insert(i);
            divs.insert(N/i);
        }
    }
    for (long long x: divs)
        cout << x << '\n';
    return 0;
}
