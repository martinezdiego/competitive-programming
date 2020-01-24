
Búsqueda en anchura sobre grafos. 
Recibe un nodo inicial u y visita todos los nodos alcanzables desde u.
BFS tambien halla la distancia mas corta entre el nodo inicial u y los demas nodos si todas las aristas tienen peso 1.

const int MAX = 100005;     //Cantidad maxima de nodos
vector<int> g[MAX];         //Lista de adyacencia
long long dist[MAX];        //Almacena la distancia a cada nodo
int N, M;                   //Cantidad de nodos y aristas

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

        // if adyacency matrix is used
        /* for (int i = 0; i < n; i++) {
            int v = g[u][i];
            if (v and dist[i] == -1) {
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        } */
    }
}

void init() {
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        visited[i] = false;
    }
}