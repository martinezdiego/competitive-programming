#include <bits/stdc++.h>

using namespace std;

int get_digits_sum(int n) {
    int sum = 0;
    while (n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        int cnt_a = 0;
        int cnt_b = 0;
        while (n--) {
            int a, b;
            cin >> a >> b;
            int sa = get_digits_sum(a);
            int sb = get_digits_sum(b);
            if (sa > sb)
                cnt_a++;
            else if (sb > sa)
                cnt_b++;
            else
                cnt_a++, cnt_b++;
        }
        if (cnt_a > cnt_b)
            cout << 0 << ' ' << cnt_a << '\n';
        else if (cnt_b > cnt_a)
            cout << 1 << ' ' << cnt_b << '\n';
        else
            cout << 2 << ' ' << cnt_a << '\n';
    }
}
