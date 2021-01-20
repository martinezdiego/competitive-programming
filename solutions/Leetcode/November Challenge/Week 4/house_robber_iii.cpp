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
    map<TreeNode*, int> rob_map;
    map<TreeNode*, int> not_rob_map;
    
    int helper(TreeNode* node, bool parent_robbed) {
       if (!node)
           return 0;
        
        if (parent_robbed)
        {
            if (rob_map.find(node) != rob_map.end()) {
                return rob_map[node];
            }
            int result = helper(node->left, false) + helper(node->right, false);
            rob_map[node] = result;
            return result;
        }
        else
        {
            if (not_rob_map.find(node) != not_rob_map.end()) {
                return not_rob_map[node];
            }
            int take = node->val + helper(node->left, true) + helper(node->right, true);
            int not_take = helper(node->left, false) + helper(node->right, false);
            int result = max(take, not_take);
            not_rob_map[node] = result;
            return result;
        }
    }
//     vector<int> helper(TreeNode* node) {
//         if (!node)
//             return {0, 0};
        
//         vector<int> left = helper(node->left);
//         vector<int> right = helper(node->right);
        
//         int take = node->val + left[1] + right[1];
        
//         int not_take = max(left[0], left[1]) + max(right[0], right[1]);
        
//         return {take , not_take};
//     }
    
public:
    int rob(TreeNode* root) {
        // vector<int> ans = helper(root);
        // return max(ans[0], ans[1]);
        return helper(root, false);
    }
};
