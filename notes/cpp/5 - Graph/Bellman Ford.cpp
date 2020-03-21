/* 
Dado un grafo con pesos, positivos o negativos. 
Halla la ruta de costo mínimo entre un nodo inicial u y todos los demás nodos.
Halla ciclos negativos.
Complejidad: O(N^3)
*/

#define INF (1LL << 62)
#define MAX 100005             

vector<pair<int,int>> g[MAX];       
long long dist[MAX];                
// vector<int> cycle;               
int N, M;

void bellmanFord(int u) {
    dist[u] = 0;
    for (int i = 0; i < N-1; i++)
        for (int j = 0; j < N; j++)
            if (dist[j] != INF)
                for (auto v : g[u])
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
    
    // para encontrar ciclos negativos
    for (u = 0; u < N; u++)
        if (dist[u] != INF)
            for (auto v : g[u])
                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = -INF;
                    // cycle.push_back(v.first);
                }
}   

void init() {
    for (int i = 0; i <= N; i++) {
        g[i].clear();
        dist[i] = INF;
    }
}