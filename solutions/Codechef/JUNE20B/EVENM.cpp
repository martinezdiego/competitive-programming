#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        
        int m[n][n];
        
        int k = 1;
        
        for (int i = 0; i < n; i++) {
            if (i%2 == 0) {
                for (int j = 0; j < n; j++)
                    m[i][j] = k++;
            } 
            else {
                k += n - 1;
                for (int j = 0; j < n; j++) {
                    m[i][j] = k--;
                }
                k = m[i][0] + 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << ' ';
                cout << m[i][j];
            }
            cout << '\n';
        }
    }
}
