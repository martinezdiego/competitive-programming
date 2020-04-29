#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) 
    {
		cout << "Case #" << tt << ":\n";
		int n;
        cin >> n;
        //trivial construction for very small n
        if (n < 30) {
            for (int i = 0; i < n; i++)
                cout << i +  1 << " 1\n";
            continue;
        }
        //construction for big n based on binary
        n -= 30;
        bool side = true;
        int cnt = 0;
        for (int i = 0; i < 30; i++) {
            //move to current row
            cout << i + 1 << ' ' << (side ? 1 : i + 1) << '\n';
            if ((n >> i) & 1) {
                //2^i in binary rep of n, traverse row to add 2^i-1
                if (side)
                    for (int j = 1; j <= i; j++)
                        cout << i + 1 << ' ' << j + 1 << '\n';
                else
                    for (int j = i - 1; j >= 0; j--)
                        cout << i + 1 << ' ' << j + 1 << '\n';
                side = !side;
                //additional 1 later
                cnt++;
            }
        }
        //add additional ones
        for (int i = 30; cnt; i++, cnt--) {
            //move to current row
            cout << i + 1 << ' ' << (side ? 1 : i + 1) << '\n';
        }
	}
}
