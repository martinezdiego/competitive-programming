/*
 * Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

    Note that the root node is at depth 1.

    The adding rule is:

    Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
    cur's original left subtree should be the left subtree of the new left subtree root.
    cur's original right subtree should be the right subtree of the new right subtree root.
    If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 */ 

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        vector<vector<TreeNode*> > layers;
        vector<TreeNode*> layer;
        layer.push_back(root);
        while (!layer.empty())
        {
            layers.push_back(layer);
            vector<TreeNode*> newLayer;
            for (TreeNode* node : layer) {
                if (node->left) {
                    newLayer.push_back(node->left);
                }
                if (node->right) {
                    newLayer.push_back(node->right);
                }
            }            
            layer = newLayer;
        }
        if (d == 1)
        {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        if (d > layers.size()) {
            for (int i = 0; i < layers.back().size(); i++) {
                {
                    TreeNode* node = new TreeNode(v);
                    node->left = layers.back()[i]->left;
                    layers.back()[i]->left = node;
                }
                {
                    TreeNode* node = new TreeNode(v);
                    node->right = layers.back()[i]->right;
                    layers.back()[i]->right = node;
                }
            }
            return root;
        }
        d -= 2;
        d = max(d, 0);
        for (int i = 0; i < layers[d].size(); i++) {
            if (layers[d][i]->left) {
                TreeNode* node = new TreeNode(v);
                node->left = layers[d][i]->left;
                layers[d][i]->left = node;
            }
            else 
            {
                TreeNode* node = new TreeNode(v);
                node->left = layers[d][i]->left;
                layers[d][i]->left = node;
            }
            if (layers[d][i]->right) {
                TreeNode* node = new TreeNode(v);
                node->right = layers[d][i]->right;
                layers[d][i]->right = node;
            }
            else
            {
                TreeNode* node = new TreeNode(v);
                node->right = layers[d][i]->right;
                layers[d][i]->right = node;
            }
        }
        return root;
    }
};
