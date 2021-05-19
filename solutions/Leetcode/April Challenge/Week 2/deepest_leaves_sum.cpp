// Given the root of a binary tree, return the sum of values of its deepest leaves.

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
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        vector<TreeNode*> layer = {root};
        while (!layer.empty())
        {
            vector<TreeNode*> newLayer;
            for (TreeNode* node : layer) {
                if (!node) continue;
                if (node->left) newLayer.push_back(node->left);
                if (node->right) newLayer.push_back(node->right);
            }
            if (newLayer.empty()) {
                for (TreeNode* node: layer) {
                    if (!node) continue;
                    ans += node->val;
                }
            }
            layer = newLayer;
        }
        return ans;
    }
};
