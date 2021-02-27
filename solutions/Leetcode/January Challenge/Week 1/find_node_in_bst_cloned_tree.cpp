 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    int original_pos;
    int clone_pos;
    bool found;
    TreeNode* ans;
    
    void dfs(TreeNode* n, TreeNode* target, bool go)
    {
        if (!n)
            return;
        
        if (go and !found) {
            original_pos++;
        }
        if (!go) {
            clone_pos++;
        }
        
        if (n == target) found = true;
        if (!go and original_pos == clone_pos) ans = n;
        
        dfs(n->left, target, go);
        dfs(n->right, target, go);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        original_pos = 0;
        clone_pos = 0;
        found = false;
        dfs(original, target, 1);
        dfs(cloned, target, 0);
        return ans;
    }
};
