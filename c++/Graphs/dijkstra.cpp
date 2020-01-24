Dado un grafo con pesos no negativos halla la ruta de costo mínimo entre un nodo inicial u y todos los demás nodos.

#define INF (1LL << 62)

struct edge
{
    int v;
    long long w;

    bool operator < (const edge & e) {
        return w > b.w;
    }
}

const int MAX = 100005;     // Cantidad maxima de nodos
vector<edge> g[MAX];        // Lista de adyacencia
bitset<MAX> visited;        // Marca los nodos como visitados
int pre[MAX];               // Almacena el nodo anterior para construir las rutas
long long dist[MAX];        // Almacena la distancia a cada nodo
int N, M;                   // Cantidad de nodos y aritas

void dijkstra(int u)
{
    priority_queue<edge> pq;
    pq.push({u, 0});
    dist[u] = 0;

    while (not pq.empty()) {
        u = pq.top().v;
        pq.pop();
        if (not visited[u]) {
            visited[u] = true;
            for (auto n : g[u]) {
                int v v.v;
                int w = v.w;
                if (not visited[v]) {
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pre[v] = u;
                        pq.push({v, dist[v]}); 
                    }
                }
            }
        }
    }
}

void init() {
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        dist[i] = INF;
        vis[i] = false;
    }
}