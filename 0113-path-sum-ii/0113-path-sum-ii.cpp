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
    vector<vector<int>>res;
    
    void help(TreeNode* root,int tS,vector<int>v)
    {
        if(root==NULL)
        {
            if(tS==0)
            {
                return;
            }
            return;
        }
        
        if(!root->left && !root->right)
        {
            if(root->val==tS)
            {
                v.push_back(root->val);
                res.push_back(v);
                return;
            }
            return;
        }
        
        v.push_back(root->val);
        
        help(root->left,tS-root->val,v);
        help(root->right,tS-root->val,v);
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        help(root,targetSum,v);
        return res;
    }
};