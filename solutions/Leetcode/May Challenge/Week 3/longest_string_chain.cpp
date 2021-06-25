class Solution {
    vector<vector<int> > edges;
    vector<int> score;
    // max string chain starting at node v
    int solve(int v)
    {
        if (score[v] != 1) return score[v];
        for (int u : edges[v]) {
            score[v] = max(score[v], solve(u) + 1);
        }
        return score[v];
    }
public:
    // O(N*L^2 + N^2)
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        edges.assign(N, vector<int>());
        score.assign(N, 1);
        unordered_map<string, int> position;
        for (int i = 0; i < N; i++) {
            position[words[i]] = i;
        }
        // O(N*L^2)
        for (int i = 0; i < N; i++) {
            string & word = words[i];
            int len = word.size();
            for (int k = 0; k < len; k++) {
                string sub = word.substr(0, k) + word.substr(k + 1);
                auto it = position.find(sub);
                if (it != position.end()) {
                    edges[it->second].push_back(i);
                }
            }
        }
        int ans = 0;
        // O(N^2)
        for (int i = 0; i < N; i++) {
            ans = max(ans, solve(i));
        }
        return ans;
    }
}; 
