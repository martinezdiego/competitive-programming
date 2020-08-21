#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int pc, pr;
		cin >> pc >> pr;
		int a = 1, b = 1;
		if (pc >= 9) {
			a = pc/9 + (pc%9 ? 1 : 0);
		}
		if (pr >= 9) {
			b = pr/9 + (pr%9 ? 1 : 0);
		}
		if (b <= a)
			cout << 1 << ' ' << b << '\n';
		else
			cout << 0 << ' ' << a << '\n';
	}
	return 0;
}