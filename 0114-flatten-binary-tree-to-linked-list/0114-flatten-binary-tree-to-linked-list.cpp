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
    vector<TreeNode*>v;
    
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        if(!root->right && !root->left)
        {
            v.push_back(root);
            return;
        }
        
        v.push_back(root);
        helper(root->left);
        helper(root->right);
        return;
    }
    
    void flatten(TreeNode* root) {
        helper(root);
        int n = v.size();
        if(n==1 || n==0)
            return;
        
        TreeNode* head = v[0];
        head->left=NULL;
        TreeNode* tail = head;
        
        for(int i=1;i<n;i++)
        {
            tail->right = v[i];
            tail = v[i];
            tail->left = NULL;
        }
        tail->right = NULL;
        root = head;
        return;
    }
};