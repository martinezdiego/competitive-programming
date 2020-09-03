#include <iostream>

using namespace std;

int main()
{
    int d, t, s;
    cin >> d >> t >> s;
    cout << (d <= t * s ? "Yes" : "No") << '\n';
    return 0;
}
