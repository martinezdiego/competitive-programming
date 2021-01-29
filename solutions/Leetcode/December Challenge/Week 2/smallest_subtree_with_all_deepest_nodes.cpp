 
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
private:
    map<TreeNode*, int> depth;
    int max_depth;
    
    void dfs(TreeNode* node, TreeNode* parent)
    {
        if (!node)
            return;
        
        depth[node] = depth[parent] + 1;
        dfs(node->left, node);
        dfs(node->right, node);
    }
    
    TreeNode* lca(TreeNode* node)
    {
        if (!node)
            return nullptr;
        
        if (depth[node] == max_depth)
            return node;
        
        TreeNode* L = lca(node->left);
        TreeNode* R = lca(node->right);
        
        if (L and R) return node;
        if (L) return L;
        if (R) return R;
        
        return nullptr;
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth[nullptr] = -1;
        dfs(root, nullptr);
        max_depth = -1;
        for (const auto & p : depth) {
            max_depth = max(max_depth, p.second);
        }
        TreeNode* ans = lca(root);
        return ans;
    }
};
