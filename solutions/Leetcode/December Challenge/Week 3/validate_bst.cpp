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
    long long prev = LLONG_MIN;
    
    // recursive preorder traversal with valid range
    bool dfs(TreeNode* node, long long low, long long high)
    {
        if (!node)
            return true;
        
        if (node->val <= low or node->val >= high)
            return false;
        
        bool ok = true;
    
        ok &= dfs(node->left, low, node->val);
        ok &= dfs(node->right, node->val, high);
        
        return ok; 
    }
    
    // iterative preorder traversal with valid range
    bool dfsIterative(TreeNode* root) {
        long long low = LLONG_MIN;
        long long high = LLONG_MAX;
        
        stack<TreeNode*> nodes;
        stack<long long> upper_limits;
        stack<long long> lower_limits;
        
        nodes.push(root); lower_limits.push(low); upper_limits.push(high);
        
        while (!nodes.empty())   
        {
            root = nodes.top(); nodes.pop();
            low = lower_limits.top(); nodes.pop();
            high = upper_limits.top(); nodes.pop();
            
            if (!root) continue;
            if (low > LLONG_MIN && root->val <= low) return false;
            if (high < LLONG_MAX && root->val >= high) return false;
            
            nodes.push(root->left); lower_limits.push(low); upper_limits.push(root->val);
            nodes.push(root->right); lower_limits.push(root->val); upper_limits.push(high);
        }
        return true;
    }
    
    // recursive inorder traversal
    bool inorder(TreeNode* node)
    {
        if (!node)
            return true;
        
        if (!inorder(node->left))
            return false;
        
        if (prev > LLONG_MIN && node->val <= prev)
            return false;
        
        prev = node->val;
        
        return inorder(node->right);
    }
    
    // iterative inorder traversal
    bool inorderIterative(TreeNode* root)
    {
        stack<TreeNode*> nodes;
        prev = LLONG_MIN;
        
        while (!nodes.empty() || root != nullptr)
        {
            while (root) {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top(); nodes.pop();
            if (prev > LLONG_MIN && root->val <= prev) return false;
            prev = root->val;
            root = root->right;
        }
        return true;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        // return dfs(root, -(1LL << 32), (1LL << 32));
        return inorder(root);
    }
};
