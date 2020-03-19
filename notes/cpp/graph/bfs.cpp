/*
Búsqueda en amplitud sobre grafos. 
Recibe un nodo inicial u y visita todos los nodos alcanzables desde u.
Como un recorrido por niveles sobre arboles.
Halla la distancia mas corta entre el nodo inicial u y los demas nodos si todas las aristas tienen peso 1.
Complejidad: O(N)
*/

#define MAX 100005
vector<int> g[MAX];         
long long dist[MAX];        
int N, M;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;

    while (not q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void init() {
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        dist[i] = -1;
    }
}