#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005

int N, M;
int cnt;
vector<int> adj[MAXN];
vector<bool> visited;

void dfs(int v)
{
    if (visited[v])
        return;
    
    visited[v] = true;
    cnt++;
    for (auto u : adj[v])
        dfs(u);
}

int main()
{
    cin >> N >> M;
    visited.assign(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        dfs(i);
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
