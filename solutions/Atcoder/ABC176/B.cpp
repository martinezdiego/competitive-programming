#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;
    int s = 0;
    while (cin >> c) {
        s += (c-'0');
        s %= 9;
    }
    cout << (s ? "No" : "Yes") << '\n';
    return 0;
}
