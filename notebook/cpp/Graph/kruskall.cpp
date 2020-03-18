Dado un grafo con pesos halla su árbol cobertor mínimo.
IMPORTANTE: Debe agregarse Disjoint Set.

struct edge {
    int u, v, w;
};

bool cmp(const edge & a, const edge & b) {
    return a.w < b.w;
}

const int MAX = 100005;         // Cantidad maxima de nodos
vector<pair<int,int>> g[MAX];   // Lista de adyacencia
vector<edge> edges;             // Lista de arcos
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