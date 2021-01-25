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
    vector<int> nodes;
    void dfs(TreeNode* node)
    {
        if (!node)
            return;
        
        dfs(node->left);
        nodes.push_back(node->val);
        dfs(node->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* ans = new TreeNode(nodes[0]);
        TreeNode* cur = ans;
        for (int i = 1; i < nodes.size(); i++)
        {
            cur->right = new TreeNode(nodes[i]);
            cur = cur->right;
        }
        return ans;
    }
}; 
