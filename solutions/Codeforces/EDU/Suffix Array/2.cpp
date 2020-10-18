#include <algorithm>
#include <iostream>

using namespace std;

void count_sort(int p[], int c[], int n)
{
    int cnt[n] = {0};
    
    for (int i = 0; i < n; i++) {
        int key = c[i];
        cnt[key]++;
    }
    
    int pos[n];
    pos[0] = 0;
    
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    
    int p_new[n];
    
    for (int i = 0; i < n; i++) {
        int key = c[p[i]];
        p_new[pos[key]] = p[i];
        pos[key]++;
    }
    
    for (int i = 0; i < n; i++) {
        p[i] = p_new[i];
    }
}

void radix_sort(pair<pair<int, int>, int> a[], int n, bool cmp)
{
    int cnt[n] = {0};
    
    for (int i = 0; i < n; i++) {
        int key = (cmp ? a[i].first.second : a[i].first.first);
        cnt[key]++;
    }
    
    int pos[n];
    pos[0] = 0;
    
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    
    pair<pair<int, int>, int> a_new[n];
    
    for (int i = 0; i < n; i++) {
        int key = (cmp ? a[i].first.second : a[i].first.first);
        a_new[pos[key]] = a[i];
        pos[key]++;
    }
    
    for (int i = 0; i < n; i++) {
        a[i] = a_new[i];
    }
}

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
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n)%n;
        }
        
        count_sort(p, c, n);
//         pair<pair<int, int>, int> a[n];
//         
//         for (int i = 0; i < n; i++) {
//             a[i] = {{c[i], c[i + (1 << k)%n]}, i};
//         }
//         
//         radix_sort(a, n, true);
//         radix_sort(a, n, false);
//         
        
        int c_new[n];
        c_new[p[0]] = 0;
        
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k))%n] };
            pair<int, int> cur = { c[p[i]], c[(p[i] + (1 << k))%n] };
            
            if (prev == cur) {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else {
                c_new[p[i]] = c_new[p[i - 1]] + 1; 
            }
        }
        
        for (int i = 0; i < n; i++) {
            c[i] = c_new[i];
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
