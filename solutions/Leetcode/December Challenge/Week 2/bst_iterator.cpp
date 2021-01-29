 
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
class BSTIterator {
private:
    vector<TreeNode*> inorder;
    int idx = -1;
    
    void dfs(TreeNode* node)
    {
        if (!node)
            return;
        
        dfs(node->left);
        inorder.push_back(node);
        dfs(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        if (idx + 1 < inorder.size())
            idx++;
        
        return inorder[idx]->val;
    }
    
    bool hasNext() {
        if (idx + 1 < inorder.size())
            return true;
        
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
