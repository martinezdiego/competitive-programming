#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define INF (1LL << 30)

char m[MAXN][MAXN];
long long dist[MAXN][MAXN];
    
int r, c;
int sx, sy;
int dx, dy;

int dirx[] = { 0, 0, -1, 1 };
int diry[] = { -1, 1, 0, 0 };

bool check(int x, int y)
{
    return (x >= 1 and x <= r and y >= 1 and y <= c and m[x][y] == '.');
}

void bfs(int x, int y)
{
    deque<pair<int,int>> q;
    q.push_front({ x, y });
    dist[x][y] = 0;
    
    while (not q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop_front();
        
        x = cur.first;
        y = cur.second;
        
        for (int i = 0; i < 4; i++) {
            if (check(x + dirx[i], y + diry[i])) {
                if (dist[x + dirx[i]][y + diry[i]] > dist[x][y]) {
                    dist[x + dirx[i]][y + diry[i]] = dist[x][y];
                    q.push_front({ x + dirx[i], y + diry[i] });
                }
            }
        }
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (check(x + i, y + j)) {
                    if (dist[x + i][y + j] > dist[x][y] + 1) {
                        dist[x + i][y + j] = dist[x][y] + 1;
                        q.push_back({ x + i , y + j });
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> r >> c;
    cin >> sx >> sy;
    cin >> dx >> dy;
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> m[i][j];
            dist[i][j] = INF;
        }
    }
    
    bfs(sx, sy);

    cout << (dist[dx][dy] == INF ? -1 : dist[dx][dy]) << '\n';
    
    return 0;
}
