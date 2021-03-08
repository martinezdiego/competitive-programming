class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N, -1);
        for (int i = 0; i < N; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[0] = 0;
                while (!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    for (int u : graph[v]) {
                        if (color[u] == -1) {
                            color[u] = (color[v] + 1)%2;
                            q.push(u);
                        }
                        else if (color[u] == color[v]) {
                            return false;
                        }
                    }
                }
            }   
        }
        return true;
    }
};
