// Given the root of a binary tree, flatten the tree into a "linked list":
// 
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

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
    vector<TreeNode*> v;
    void dfs(TreeNode* root)
    {
        if (!root) return;
        v.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        dfs(root);
        int N = v.size();
        for (int i = 1 ; i < N; i++) {
            v[i - 1]->right = v[i];
            v[i - 1]->left = nullptr;
        }
        v.back()->left = nullptr;
        v.back()->right = nullptr;
    }
}; 
