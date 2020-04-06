#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        int m[n][n]; 
        int trace = 0;
        int rows = 0;
        int cols = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
                if (i == j)
                    trace += m[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            set<int> row, col;
            for (int j = 0; j < n; j++) {
                row.insert(m[i][j]);
                col.insert(m[j][i]);
            }
            if (row.size() < n) rows++;
            if (col.size() < n) cols++;
        }
        cout << trace << ' ' << rows << ' ' << cols << '\n';
    }
    return 0;
}