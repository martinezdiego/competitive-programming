#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;
vector<int> sz;

void init() {
    parent.assign(N + 1, 0);
    sz.assign(N + 1, 1);
    for (int i = 1; i <= N; i++)
        parent[i] = i;
}

int find(int i) {
    if (parent[i] == i)
        return i;
    
    return find(parent[i]);
}

bool same(int i, int j) {
    return find(i) == find(j);
}

void join(int i, int j) {
    int u = find(i);
    int v = find(j);
    
    if (u == v)
        return;
    
    if (sz[u] > sz[v])
        swap(u, v);

    parent[u] = v;
    sz[v] += sz[u];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    
    init();
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }
    
    int ans = 0;
    
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) ans++;
    }
    
    cout << ans - 1 << '\n';
}
