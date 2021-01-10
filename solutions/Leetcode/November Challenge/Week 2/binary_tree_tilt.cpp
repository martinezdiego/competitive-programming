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
    int totalTilt = 0;
    
    int getSum(TreeNode* node) {
        if (!node)
            return 0;
        
        int lsum = getSum(node->left);
        int rsum = getSum(node->right);
        
        // process current node
        int tilt = abs(lsum - rsum);
        totalTilt += tilt;
        
        return node->val + lsum + rsum;
    }
public:
    int findTilt(TreeNode* root) {
        getSum(root);
        return totalTilt;
    }
}; 
