Dado un grafo con pesos, positivos o negativos.
halla la ruta de costo mínimo entre un nodo inicial u y todos los demás nodos.
Tambien halla ciclos negativos.

#define INF (1LL << 62)

const int MAX = 100005;             // Cantidad maxima de nodos
vector<pair<int,int>> g[MAX];       // Lista de adyacencia
long long dist[MAX];                // Almacena la distancia a cada nodo
// vector<int> cycle;               // Para construir el ciclo negativos
int N, M;                           // Cantidad de nodos y aristas

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
                if (dist[v.first] > dist[u] + v.second) { // ciclo negativo
                    dist[v.first] = -INF;
                    // cycle.push_back(v.first); // reconstruye el ciclo
                }
}   

void init() {
    for (int i = 0; i <= N; i++) {
        g[i].clear();
        dist[i] = INF;
    }
}