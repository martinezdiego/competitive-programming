/*
Modificación del BFS para detectar si un grafo es bipartito.
Complejidad: O(N)
*/

#define MAX 100005     

vector<int> g[MAX];         
int color[MAX];             
bool bipartite;             
int N, M;                   

void bfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0;
    
    while (not q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (color[v] == -1) {
                color[v] = (color[u] + 1)%2;
                q.push(v);
            } 
            else if (color[v] == color[u]) {
                bipartite = false;
                return;
            }
        }
    }
}

void init() {
    bipartite = true;
    for(int i = 0; i <= N; i++) {
        g[i].clear();
        color[i] = -1;
    }
}