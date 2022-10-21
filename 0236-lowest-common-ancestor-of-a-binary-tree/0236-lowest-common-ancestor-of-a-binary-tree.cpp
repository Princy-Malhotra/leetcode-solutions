/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool search(TreeNode* root,TreeNode* p)
    {
        if(root==NULL)
            return false;
        
        if(!root->left && !root->right)
        {
            if(root==p)
                return true;
            
            return false;
        }
        
        return search(root->left,p) || search(root->right,p);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        
        if (root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right)
            return root;
        
        return left ? left: right;
    }
};