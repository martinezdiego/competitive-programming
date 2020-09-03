#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAXN 200005

int N, M;
vector<int> parent;
vector<int> sz;

void init()
{
    parent.assign(N+1, 1);
    sz.assign(N+1, 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int find(int v)
{
    if (parent[v] == v)
        return v;
    
    return find(parent[v]);
}

bool same(int u, int v)
{
    return find(u) == find(v);
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);
    
    if (u == v)
        return;
    
    if (sz[u] > sz[v])
        swap(u, v);
    
    parent[u] = v;
    sz[v] += sz[u];
}

int main()
{
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }
    set<int, greater<int> > s;
    for (int i = 1; i <= N; i++) {
        s.insert(sz[i]);
    }
    cout << *s.begin() << '\n';
    return 0;
}
