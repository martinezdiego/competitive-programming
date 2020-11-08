class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // base case
        if (n < 2) {
            vector<int> centroids = {0};
            return centroids;
        }
        // initialize adjacency list
        vector<set<int>> adj(n);
        for (vector<int> e : edges) {
            int x = e[0];
            int y = e[1];
            adj[x].insert(y);
            adj[y].insert(x);
        }
        // initialize first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1)
                leaves.push_back(i);
        }
        // trim the leaves until reaching the centroids
        int remaining = n;
        while (remaining > 2) {
            remaining -= leaves.size();
            vector<int> newLeaves;
            // remove the current leaves along with the edges
            for (int leaf : leaves) {
                // the only neighbor left for the leaf node
                int neighbor = *(adj[leaf].begin());
                // remove the edge along with the leaf node
                adj[neighbor].erase(leaf);
                if (adj[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }
            // prepare for the next round
            leaves = newLeaves;
        }
        // return the centroids
        return leaves;
    }
};
