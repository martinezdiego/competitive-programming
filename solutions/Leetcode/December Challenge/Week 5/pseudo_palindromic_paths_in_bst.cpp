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
    int cnt;
    
    void dfs(TreeNode* node, int pathsum)
    {
        if (!node)
            return;
        
        pathsum ^= (1 << node->val);
        
        if (!node->left and !node->right) {
            // is a power of two
            // only one digit 1
            if ((pathsum & (pathsum - 1)) == 0)
                cnt++;
        }
        
        dfs(node->left, pathsum);
        dfs(node->right, pathsum);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        cnt = 0;
        dfs(root, 0);
        return cnt;
    }
};
