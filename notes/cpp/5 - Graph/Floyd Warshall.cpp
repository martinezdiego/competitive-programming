/*
Dado un grafo halla la distancia mínima entre cualquier par de nodos. 
g[i][j] almacena la distancia mínima entre el nodo i y el j.
Complejidad: O(N^3)
*/

#define INF (1LL << 62)
#define MAX 505
    
long long g[MAX][MAX];  
int N, M;               

void floydWarshall() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init() {
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= N; j++)
            g[i][j] = (i == j ? 0 : INF);
    
}