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
    int idx = 0;
    void inorder(TreeNode* root, bool replace)
    {
        if (!root) 
            return;
        inorder(root->left, replace);
        
        if (!replace) 
            nodes.push_back(root->val);
        else
            root->val = nodes[idx++];
        
        inorder(root->right, replace);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        inorder(root, false);
        int N = nodes.size();
        for (int i = N-1; i > 0; i--) {
            nodes[i-1] += nodes[i];
        }
        inorder(root, true);
        return root;
    }
};
