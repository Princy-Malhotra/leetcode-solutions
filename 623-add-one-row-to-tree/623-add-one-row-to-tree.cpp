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
    
    TreeNode* helper(TreeNode* root,int val,int depth,int level)
    {
        if(level==depth-1)
        {
            TreeNode* templeft;
            TreeNode* tempright;
            if(root->left)
            templeft = root->left;
            
            if(root->right)
            tempright = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = templeft;
            root->right->right = tempright;
            return root;
        }
        
        if(root->left)
        root->left = helper(root->left,val,depth,level+1);
        
        if(root->right)
        root->right = helper(root->right,val,depth,level+1);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        
        return helper(root,val,depth,1);
    }
};