Determina si un Grafo DIRIGIDO tiene o no ciclos.
SE DEBEN LIMPIAR LAS ESTRUCTURAS DE DATOS ANTES DE UTILIZARSE

const int MAX = 10010;          // Cantidad maxima de nodos
int v;                          // Cantidad de Nodos del grafo
vector<int> g[MAX];             // Estructura para almacenar el grafo
int flag[MAX];                  // 0: unvisited, 1: visited, 2: explored  
bool loop;                      // Para verificar si tiene un ciclo

void check(int u) {
	
	if(loop) 
        return;
	
	flag[u] = 2;
	
	for(auto v : g[u]) {
		if (flag[v] == -1)	
            check(v);
		else if (flag[v] == 2) {
			loop = true;
			break;
		}
	}
	
	flag[u] = 3;
}