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
    int result;
    void maxAncestorDiffRecursive(TreeNode* root, int curMax, int curMin) {
        if (!root)
            return;
        
        int ans1 = abs(curMax - root->val);
        int ans2 = abs(curMin - root->val);
        
        result = max(result, max(ans1, ans2));
        
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);
        
        maxAncestorDiffRecursive(root->left, curMax, curMin);
        maxAncestorDiffRecursive(root->right, curMax, curMin);
        
        return;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        result = 0;
        maxAncestorDiffRecursive(root, root->val, root->val);
        return result;
    }
};
