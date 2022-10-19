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
    vector<int> rightSideView(TreeNode* root) {
        
        
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        if(root==NULL)
            return v;
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp==NULL)
            {
                if(q.empty())
                    break;
                
                else
                    q.push(NULL);
            }
            
            else{
                if(q.front()==NULL)
                {
                    v.push_back(temp->val);
                }
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }
        }
        return v;
    }
};