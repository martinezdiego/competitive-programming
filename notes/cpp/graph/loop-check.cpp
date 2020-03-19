// Determina si un grafo dirigido tiene o no ciclos.

#define MAX 10010          		

vector<int> g[MAX];             
int status[MAX];		// 0: no visitado, 1: visitado, 2: explorado  
bool loop;
int N;    

void check(int u) {
	if(loop) 
        return;

	status[u] = 2;
	
	for(auto v : g[u]) {
		if (not status[v])	
            check(v);
		else if (status[v] == 2) {
			loop = true;
			break;
		}
	}
	
	status[u] = 1;
}

int main()
{
	for( int i = 1; i <= N and (not loop); i++ ){ 		//si el grafo es NO conexo
		if(not status[i]) check(i);
	}
}
