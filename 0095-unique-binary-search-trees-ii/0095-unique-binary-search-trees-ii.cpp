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
    
    vector<TreeNode*> helper(int st,int e)
    {
        vector<TreeNode*> v;
        if(st>e)
        {
            v.push_back(NULL);
            return v;
        }
        
        /*if(st==e)
        {
            TreeNode* temp = new TreeNode(st);
            v.push_back(temp);
            return v;
        }
        
        /*if(dp[st][e].size()!=0)
            return dp[st][e];*/
        
        for(int i=st;i<=e;i++)
        {
            
            vector<TreeNode*> sal = helper(st,i-1);
            vector<TreeNode*> sar = helper(i+1,e);
            for(int j=0;j<sal.size();j++)
            {
                for(int k=0;k<sar.size();k++)
                {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = sal[j];
                    temp->right = sar[k];
                    v.push_back(temp);
                }
            }
        }
       // dp[st][e] = v;
        return v;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return helper(1,n);
        
    }
};