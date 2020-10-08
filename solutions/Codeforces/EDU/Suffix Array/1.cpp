#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    s.push_back('$');
    
    int n = s.size();
    
    int p[n], c[n];
    
    {
        pair<char, int> a[n];
        
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        
        sort(a, a + n);
        
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        
        c[p[0]] = 0;
        
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            }
            else {
                c[p[i]] = c[p[i - 1]] + 1; 
            }
        }
    }
    
    int k = 0;
    
    while ((1 << k) < n) 
    {
        pair<pair<int, int>, int> a[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[i + (1 << k)%n]}, i};
        }
        
        sort(a, a + n);
        
        for (int i = 0; i < n; i++) p[i] = a[i].second;

        c[p[0]] = 0;
        
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            }
            else {
                c[p[i]] = c[p[i - 1]] + 1; 
            }
        }
        k++;
    }
    
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << p[i];
    }
    cout << '\n';
    
    return 0;
}
