class Solution {
private:
    vector<bool> visited;
    unordered_map<int, vector<int>> adj;

    int bfs(int v, vector<int> & arr) {
        int N = arr.size();
        vector<int> curs;
        visited.assign(N + 1, false);
        
        for (int i = 0; i < N; i++) {
            adj[arr[i]].push_back(i);
        }
        
        curs.push_back(v);
        int cnt = 0;
        
        // traverse layer by layer
        while (!curs.empty()) {
            vector<int> nex;    
            for (int v : curs) 
            {
                if (v == N - 1) return cnt;
                
                // check same value
                for (int u : adj[arr[v]]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        nex.push_back(u);
                    }
                }
                
                // clear adj list to prevent redudant search
                adj[arr[v]].clear();

                // check neighbors
                if (v + 1 < N and !visited[v + 1]) {
                    nex.push_back(v + 1);
                    visited[v + 1] = true;
                }
                if (v - 1 >= 0 and !visited[v - 1]) {
                    nex.push_back(v - 1);
                    visited[v - 1] = true;
                }
            }    
            curs = nex;
            cnt++;
        }
        return 0;
    }
public:
    int minJumps(vector<int>& arr) {
        int N = arr.size();
        if (N == 1) return 0;
        int ans = bfs(0, arr);
        return ans;
    }
};
