// Dado un grafo halla el costo total de su arbol cobertor mínimo.

#define MAX 100005

struct edge {
    int v;
    long long w;
    
    bool operator < (const edge & b) const {
        return w < b.w;     
    }
};

vector<edge> g[MAX];        
bool visited[MAX];        
long long ans;              
int N, M;

void prim() {
    priority_queue<edge> pq;
    visited[0] = true;
    for (const auto & v : g[0]) {
        if (not visited[v.v]) 
            pq.push(v);
    }
    
    while (not pq.empty()) {
        edge e = pq.top(); 
        pq.pop(); 
        int u = e.v;
        if (not visited[u]) {
            ans += e.w;
            visited[u] = true;
            for (const auto & v : g[u]) {
                if (not visited[v.v]) 
                    pq.push(v);
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