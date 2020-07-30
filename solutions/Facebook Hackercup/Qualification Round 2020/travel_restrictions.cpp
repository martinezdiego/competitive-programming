#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ":\n";
		
		int n;
		cin >> n;
		char m[n][n];
		char airlines[2][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					m[i][j] = 'Y';
				else
					m[i][j] = 'X';
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> airlines[i][j];
			}
		}
		for (int i = 0; i + 1 < n; i++) {
			if (airlines[0][i] == 'Y' and airlines[1][i+1]  == 'Y')
				m[i+1][i] = 'Y';
			else
				m[i+1][i] = 'N';
			if (airlines[0][i+1] == 'Y' and airlines[1][i]  == 'Y')
				m[i][i+1] = 'Y';
			else
				m[i][i+1] = 'N';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (m[i][j] == 'X') {
                    int row, col;
                    bool ok = true;
                    if (i < j) {
                        row = i;
                        col = i+1;
                        assert(col < n);
                        while (col <= j) {
                            ok &= (m[row][col] == 'Y');
                            row++;
                            col++;
                        }
                    }
                    else {
                        row = i;
                        col = i-1;
                        assert(col >= 0);
                        while (col >= j) {
                            ok &= (m[row][col] == 'Y');
                            row--;
                            col--;
                        }
                    }
                    if (ok)
                        m[i][j] = 'Y';
                    else
                        m[i][j] = 'N';
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
