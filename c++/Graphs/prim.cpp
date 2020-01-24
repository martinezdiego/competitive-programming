Dado un grafo halla el costo total de su arbol cobertor mínimo.

struct edge {
    int v;
    long long w;
    
    bool operator < (const edge & b) const {
        return w > b.w;     // orden invertido
    }
};

const int MAX = 100005;     //Cantidad maxima de nodos
vector<edge> g[MAX];        //Lista de adyacencia
bitset<MAX> visited;        //Marca los nodos ya visiteditados
long long ans;              //Costo total del arbol cobertor minimo
int N, M;                   //Cantidad de nodos y aristas

void prim() {
    priority_queue<edge> pq;
    visited[0] = true;
    for (const auto & n : g[0]) {
        int v = n.v;
        int w = n.w;
        if (not visited[v]) 
            pq.push({v, w});
    }
    
    while (not pq.empty()) {
        edge e = pq.top(); 
        pq.pop(); 
        int u = e.v;
        if (not visited[u]) {
            ans += e.w;
            visited[u] = true;
            for (const auto & n : g[u]) {
                int v = n.v;
                int w = n.w;
                if (not visited[v]) 
                    pq.push({v, w});
            }
        }
    }
}

void init() {
    ans = 0;
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        visited[i] = false;
    }
}