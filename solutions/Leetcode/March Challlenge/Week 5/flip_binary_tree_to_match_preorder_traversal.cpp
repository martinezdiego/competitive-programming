// You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.
// 
// Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:
// 
// Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.
// 
// Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].

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
    vector<int> ans;
    int idx;
    
    void dfs(TreeNode* root, vector<int> & voyage)
    {
        if (!root) 
            return;
        
        if (root->val != voyage[idx++]) {
            ans.clear();
            ans.push_back(-1);
            return;
        }
        
        if (idx < voyage.size() and root->left != nullptr and root->left->val != voyage[idx]) {
            ans.push_back(root->val);
            dfs(root->right, voyage);
            dfs(root->left, voyage);
        }
        else {
            dfs(root->left, voyage);
            dfs(root->right, voyage);
        }
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        idx = 0;
        dfs(root, voyage);
        if (!ans.empty() and ans[0] == -1) return {-1};
        return ans;
    }
};
