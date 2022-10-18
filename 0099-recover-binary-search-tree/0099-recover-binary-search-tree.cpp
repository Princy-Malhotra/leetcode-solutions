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
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        if(!root->right && !root->left)
        {
            v.push_back(root);
            return;
        }
        
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
        return;
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int n=v.size();
        for(int i=0;i<n;i++)
            cout<<v[i]->val<<" ";
        cout<<endl;
        
        int fi=-1;
        int se=-1;
        for(int i=0;i<n-1;i++)
        {
            if(v[i]->val>v[i+1]->val && fi==-1)
            {
                fi=i;
            }
            if(fi!=-1 && v[i]->val>v[i+1]->val)
            {
                se = i+1;
            }
        }
        
        if(fi==-1 || se==-1)
            return;
        
        int temp = v[fi]->val;
        v[fi]->val = v[se]->val;
        v[se]->val = temp;
        return;
    }
};