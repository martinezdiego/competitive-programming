/*
Dado un grafo con pesos halla su árbol cobertor mínimo.
Debe agregarse Disjoint Set.
Complejidad: O(Nlog(N))
*/

#define MAX 100005

struct edge {
    int u, v, w;
};

bool cmp(const edge & a, const edge & b) {
    return a.w < b.w;
}

vector<pair<int,int>> g[MAX];   
vector<edge> edges;
int N, M;

void kruskall() {
    dsu ds(N);
    sort(e.begin(), e.end(), cmp);
    for (const auto & e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            ds.unite(e.u, e.v);
            g[e.u].push_back({e.v, e.w});
            g[e.v].push_back({e.u, e.w});
        }
    }
}

void init() {
    edges.clear();
    for (int i = 0; i <= N; i++)
        g[i].clear();
}