#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans_d = 1;
	int ans_t = 40;
	for (int i = 0; i + 2 < n; i++) {
		if (max(a[i], a[i + 2]) < ans_t) {
			ans_t = max(a[i], a[i + 2]);
			ans_d = i + 1;
		}
	}
	cout << ans_d << ' ' << ans_t << '\n';
	return 0;
}