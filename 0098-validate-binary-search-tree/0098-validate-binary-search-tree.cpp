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
struct myhello{
    bool isBST;
    int mn;
    int mx;
};

class Solution {
public:
    struct myhello helper(TreeNode* root)
    {
        if(root==NULL)
        {
            myhello ans;
            ans.isBST = true;
            ans.mn = INT_MIN;
            ans.mx = INT_MAX;
            return ans;
        }
        
        if(!root->left && !root->right)
        {
            myhello ans;
            ans.isBST = true;
            ans.mn = root->val;
            ans.mx = root->val;
            return ans;
        }
        
        myhello sa1,sa2;
        if(root->left)
        sa1 = helper(root->left);
        if(root->right)
        sa2 = helper(root->right);
        
        myhello ans;
        if(root->left && root->right && sa1.isBST && sa2.isBST)
        {
            if(root->val>sa1.mx && root->val<sa2.mn)
            {
                ans.isBST = true;
                ans.mn = sa1.mn;
                ans.mx = sa2.mx;
                return ans;
            }
        }
        
        if(root->left && !root->right && sa1.isBST)
        {
            if(root->val>sa1.mx)
            {
                ans.isBST = true;
                ans.mn = sa1.mn;
                ans.mx = root->val;
                return ans;
            }
        }
        
        if(root->right && !root->left && sa2.isBST)
        {
            if(root->val<sa2.mn)
            {
                ans.isBST = true;
                ans.mn = root->val;
                ans.mx = sa2.mx;
                return ans;
            }
        }
        ans.isBST = false;
        ans.mn = min(root->val,sa1.mn);
        ans.mx = max(root->val,sa2.mx);
        return ans;
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root).isBST;
    }
};