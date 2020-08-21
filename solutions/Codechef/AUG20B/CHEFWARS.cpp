#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		double p, h;
		double s = 0.0;
		cin >> h >> p;
		bool ok = false;
		while (p >= 1.0) {
			s += p;
			p /= 2.0;
			if (s >= h) {
				ok = true;
				break;
			}
		}
		cout << (ok ? 1 : 0) << '\n';
	}
	return 0;
}