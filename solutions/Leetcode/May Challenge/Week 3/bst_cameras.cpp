/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
    // set<TreeNode*> visited;
    
    // void dfs(TreeNode* node, TreeNode* parent)
    // {
    //     if (!node) return;
    //     dfs(node->left, node);
    //     dfs(node->right, node);
    //     if ((parent == nullptr && visited.find(node) == visited.end()) || 
    //         (visited.find(node->left) == visited.end() || visited.find(node->right) == visited.end())) {
    //         ans++;
    //         visited.insert(node);
    //         visited.insert(node->left);
    //         visited.insert(node->right);
    //         visited.insert(parent);
    //     }
    // }
    
    // 0 -> no camera is covering this node
    // 1 -> is covered by a camera
    // 2 -> has a camera
    int dfs(TreeNode* node)
    {
        if (node == nullptr) return 1;
        int L = dfs(node->left);
        int R = dfs(node->right);
        // check if we need to put a camera
        if (L == 0 || R == 0) {
            ans++;
            return 2;
        }
        if (L == 2 || R == 2) {
            return 1;
        }
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        ans = 0;
        // visited.insert(nullptr);
        // dfs(root, nullptr);
        int cur = dfs(root);
        return cur == 0 ? ans + 1 : ans;
    }
};
