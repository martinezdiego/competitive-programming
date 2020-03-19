/*
Búsqueda en profundidad sobre grafos.
Recibe un nodo inicial u y visita todos los nodos alcanzables desde u.
Como un recorrido en prefijo sobre arboles.
Complejidad: O(N)
*/

#define MAX 100005     
vector<int> g[MAX];         
bool visited[MAX];          
int N, M;                   

void dfs(int u) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (not visited[v]) 
            dfs(v);
    }
}

void init() {
    for(int i = 0; i < N; i++) {
        g[i].clear();
        visited[i] = false;
    }
}
