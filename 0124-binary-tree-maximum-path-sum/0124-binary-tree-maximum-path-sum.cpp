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
    map<pair<TreeNode*,int>,int>mp;
    void helper(TreeNode* root)
    {
        if(root==NULL)
        {
            mp[{root,0}]=INT_MIN;
            mp[{root,1}]=INT_MIN;
            mp[{root,2}]=INT_MIN;
            mp[{root,3}]=INT_MIN;
            return;
        }
        
        if(!root->left && !root->right)
        {
            mp[{root,0}]=root->val;
            mp[{root,1}]=root->val;
            mp[{root,2}]=root->val;
            mp[{root,3}]=root->val;
            return;
        }
        
        if(mp.count({root,0}) && mp.count({root,1}) && mp.count({root,2}) && mp.count({root,3}))
            return;
        
        helper(root->left);
        helper(root->right);
        int sa1 = root->val;
        int sa2 = root->val;
        int sa3 = root->val;
        int sa4 = root->val;
        
        if(mp[{root->left,0}]!=INT_MIN)
        sa1 = max(max(mp[{root->left,0}],mp[{root->left,1}]) + root->val,sa1);
        
        if(mp[{root->right,0}]!=INT_MIN)
        sa2 = max(sa2,max(mp[{root->right,0}],mp[{root->right,1}]) + root->val);
        
        if(sa1!=INT_MIN && sa2!=INT_MIN)
        sa3 = max(sa3,sa1+sa2-root->val);
        
        sa4 = max(sa4,max(sa1,max(sa2,sa3)));
        mp[{root,0}]=sa1;
        mp[{root,1}]=sa2;
        mp[{root,2}]=sa3;
        //mp[{root,3}]=sa4;
        
        mp[{root,3}]= max(mp[{root->left,3}],max(mp[{root->right,3}],sa4));
        return;

    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return mp[{root,3}];
        
        
    }
};