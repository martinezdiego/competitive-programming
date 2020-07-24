#include <bits/stdc++.h>

using namespace std;

char m[8][8];

void init()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            m[i][j] = '.';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        init();
        m[0][0] = 'O';
        k--;
        for (int i = 0; i < 8; i++) {
            for (int j = (i == 0 ? 1 : 0); j < 8; j++) {
                if (i%2 == 0) {
                    if (k == 0) {
                        m[i][j] = 'X';
                    }
                    else 
                        k--;
                }
               else {
                   if (k == 0) {
                        m[i][8-j-1] = 'X';
                   }
                   else
                       k--;
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << m[i][j];
            }
            cout << '\n';
        }
    }
}
