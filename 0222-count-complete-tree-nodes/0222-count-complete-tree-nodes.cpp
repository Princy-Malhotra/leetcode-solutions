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
    //int cnt=0;
    int cntleafnodes(TreeNode* root,int l,int levels)
    {
        if(root==NULL)
            return 0;
        
        if(!root->left && !root->right)
        {
            if(l==levels)
            return 1;
            return 0;
        }
        
        return cntleafnodes(root->left,l+1,levels) + cntleafnodes(root->right,l+1,levels);
    }
    
    int helplevel(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        return 1+max(helplevel(root->left),helplevel(root->right));
            
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int levels = helplevel(root);
        //cout<<levels<<endl;
        int cnt = cntleafnodes(root,1,levels);
        //cout<<cnt<<endl;
        int a = pow(2,levels-1)-1;
        return a+cnt;
    }
};