#include <bits/stdc++.h>

using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> size;
    int N;

    DSU(int n) : N(n), parent(vector<int>(n)), size(vector<int>(n, 1)) 
    {
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        
        return find(parent[u]);
    }

    bool same(int u, int v)
    {
        return find(u) == find(v);
    }

    void unite(int u, int v)
    {   
        u = find(u);
        v = find(v);

        if (u == v)
            return;

       if (size[u] > size[v])
            swap(u, v);
        
        parent[u] = v;
        size[v] += size[u];
        N--;
    }

    int count(int u)
    {
        return size[find(u)];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    using edge = pair<pair<int,int>,int>;

    vector<edge> edges(m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {{a, b}, c};
    }

    sort(edges.begin(), edges.end(), [](const edge & a, const edge & b) {
        return a.second > b.second;
    });

    long long ans = 0;

    for (const auto & e : edges) {
        const auto & key = e.first;
        if (not dsu.same(key.first, key.second)) {
            dsu.unite(key.first, key.second);
            ans += (long long) e.second;
        }
    }

    cout << (dsu.N != 1 ? -1 : ans) << '\n';
}