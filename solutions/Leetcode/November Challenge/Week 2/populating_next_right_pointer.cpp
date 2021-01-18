/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    private:
        vector<Node*> levels[32];
        int height = 0;
        void dfs(Node* node, int depth) {
            if (!node)
                return;
            
            levels[depth].push_back(node);
            height = max(height, depth);
            
            dfs(node->left, depth + 1);
            dfs(node->right, depth + 1);
        }
public:
    Node* connect(Node* root) {
        dfs(root, 0);
        for (int i = 0; i <= height; i++) {
            for (int j = 1; j < levels[i].size(); j++) {
                levels[i][j-1]->next = levels[i][j];
            }
        }
        return root;
    }
}; 
