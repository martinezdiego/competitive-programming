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
    vector<vector<int> > levels;
    void dfs(TreeNode* root, int level)
    {
        if (!root)
            return;
        
        dfs(root->left, level + 1);
        if (level > levels.size()) {
            levels.resize(level);
        }
        levels[level - 1].push_back(root->val);
        dfs(root->right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 1);
        return levels;
    }
}; 
