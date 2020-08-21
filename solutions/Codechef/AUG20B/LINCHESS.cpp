#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		bool ok = false;
		int ans = 0;
		while (n--)
		{
			int x;
			cin >> x;
			if (k%x == 0) {
				ok = true;
				ans = max(ans, x);
			}
		}
		cout << (ok ? ans : -1) << '\n';
	}
	return 0;
}