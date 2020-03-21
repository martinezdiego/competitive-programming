/*
Dado un grafo con pesos no negativos halla la ruta de costo mínimo entre un nodo inicial u y todos los demás nodos.
Complejidad: O(Nlog(N))
*/

#define INF (1LL << 62)
#define MAX 100005     

struct edge
{
    int v;
    long long w;

    bool operator < (const edge & e) {
        return w > e.w;
    }
};

vector<edge> g[MAX];        
bool visited[MAX];        
int pre[MAX];               // almacena el nodo anterior para construir las rutas
long long dist[MAX];        
int N, M;                   

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
                int v = n.v;
                int w = n.w;
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
        visited[i] = false;
    }
}