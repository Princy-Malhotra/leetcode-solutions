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
    vector<int>arr;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        if(!root->left && !root->right)
        {
            arr.push_back(root->val);
            return;
        }
        
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
        return;
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        while(lo<hi)
        {
            if(arr[lo]+arr[hi]==k)
                return true;
            
            else if(arr[lo]+arr[hi]<k)
                lo++;
            
            else
                hi--;
        }
        return false;
    }
};