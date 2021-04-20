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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;
        vector<TreeNode*> layer;
        layer.push_back(root);
        ans.push_back(root->val * 1.0);
        int cnt = 0;
        while (!layer.empty())
        {
            vector<TreeNode*> newLayer;
            double sum = 0;
            for (TreeNode* node : layer) {
                if (node->left) {
                    newLayer.push_back(node->left);
                    sum += node->left->val;
                }
                if (node->right) {
                    newLayer.push_back(node->right);
                    sum += node->right->val;
                }
            }
            if (!newLayer.empty()) ans.push_back(sum/newLayer.size());
            
            layer = newLayer;
        }
        return ans;
    }
}; 
