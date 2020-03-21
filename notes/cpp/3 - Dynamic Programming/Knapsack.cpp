// Problema de 0-1 Mochila con DP

#define MAX_N 1005
#define MAX_W 10005
#define INF 2000000000

int dp[MAX_N][MAX_W];
int gold[MAX_N];
int weight[MAX_N];
int N;
vector<int> rb;

// Mochila bottom up 
int knapsack(int i, int w)
{
	if (w < 0) 
		return -INF;
	if (i == N) 
		return 0;
	int & ans = dp[i][w];
	if (ans != -1) 
		return ans;
	ans = max(knapsack(i + 1, w), knapsack(i + 1, w - weight[i]) + gold[i]);
	return ans;
}

// Mochila top down. 
// acceder como dp[0][W]
void knapsack2()
{
	for (int i = 0; i <= MAX_W; i++) 
		dp[N][i] = 0; 
	for (int i = N - 1; i >= 0; i--)
	{
		for (int w = 0; w <= MAX_W; w++) {
			dp[i][w] = dp[i + 1][w];
			if(w - weight[i] >= 0) 
				dp[i][w] = max(dp[i][w], dp[i + 1][w - weight[i]] + gold[i]);
		}
	}
}

// Mochila optimizando memoria. 
// Acceder como dp_opt[0][W]
int dp_opt[2][MAX_W];

void knapsack_opt()
{
	for(int i = 0; i <= MAX_W; i++) 
		dp[N%2][i] = 0; 
	for(int i = N - 1; i >= 0; i--)
	{
		for(int w = 0; w <= MAX_W; w++) {
			dp_opt[i%2][w] = dp_opt[(i + 1)%2][w];
			if(w - weight[i] >= 0) 
				dp_opt[i%2][w] = max(dp_opt[i%2][w], dp_opt[(i + 1)%2][w - weight[i]] + gold[i]);
		}
	}
}

// Reconstruir solución en rb.
// Almacena los indices de los elementos usados 
// NO FUNCIONA CON MOCHILA OPTIMIZADA. 
// Si existen multiples soluciones reconstruye la que primero aparezca. Para la ultima recorrer al revés
void build(int W)
{
	rb.clear();
	for(int i = 0; i < N and W > 0; i++) {
		if(W - weight[i] >= 0 and dp[i][W] == dp[i + 1][W - weight[i]] + gold[i])
			rb.push_back(i);
	}
}
