class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> deadset;
        for (string & s : deadends) deadset.insert(s);
        if (deadset.find("0000") != deadset.end()) return -1;
        queue<string> q;
        q.push("0000");
        int ans = 0;
        while (!q.empty()) {
            int N = q.size();
            for (int i = 0; i < N; i++)
            {
                string s = q.front(); q.pop();
                if (s == target) return ans;
                for (string & neighbor : get_neighbors(s)) {
                    if (deadset.find(neighbor) != deadset.end()) continue;
                    deadset.insert(neighbor);
                    q.push(neighbor);
                }
            }
            ans++;
        }
        return -1;
    }
    
    vector<string> get_neighbors(const string & code) {
        vector<string> adj;
        for (int i = 0; i < 4; i++) {
            int digit = code[i] - '0';
            int next = (digit - 1 + 10)%10;
            adj.push_back(code.substr(0, i) + to_string(next) + code.substr(i + 1));
            next = (digit + 1 + 10)%10;
            adj.push_back(code.substr(0, i) + to_string(next) + code.substr(i + 1));
        }
        return adj;
    }
};
