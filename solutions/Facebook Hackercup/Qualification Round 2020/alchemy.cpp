#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		string s;
        int a = 0;
        int b = 0;
        int n;
        cin >> n >> s;
        for (auto c : s) {
            if (c == 'A') a++;
            else b++;
        }
        if (abs(a-b) == 1)
            cout << "Y\n";
        else
            cout << "N\n";
	}
	return 0;
}
