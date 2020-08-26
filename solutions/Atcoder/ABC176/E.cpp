#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> row_cnt(h + 1, 0);
    vector<int> col_cnt(w + 1, 0);
    pair<int,int> target[m + 1];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        row_cnt[x]++;
        col_cnt[y]++;
        target[i].first = x;
        target[i].second = y;
    }
    int mx_row = *max_element(row_cnt.begin(), row_cnt.end());
    int mx_col = *max_element(col_cnt.begin(), col_cnt.end());
    int mx_row_cnt = 0;
    int mx_col_cnt = 0;
    vector<int> mx_cols;
    for (int i = 1; i <= h; i++) {
        if (row_cnt[i] == mx_row) mx_row_cnt++;
    }
    for (int i = 1; i <= w; i++) {
        if (col_cnt[i] == mx_col) mx_col_cnt++;
    }
    int ans = mx_row + mx_col;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int x = target[i].first;
        int y = target[i].second;
        if (row_cnt[x] == mx_row and col_cnt[y] == mx_col)
            cnt++;
    }
    cout << ans - (mx_row_cnt * mx_col_cnt == cnt) << '\n'; 
    return 0;
}
