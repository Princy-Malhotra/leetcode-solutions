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
    TreeNode* helper(vector<int>pre,vector<int>in,int prest,int pree,int inst,int ine,int n)
    {
        if(prest<0 || inst<0 || pree>=n || ine>=n || prest>pree || inst>ine)
            return NULL;
        
        int rootval = pre[pree];
        int rootidxin;
        for(int i=inst;i<=ine;i++)
        {
            if(in[i]==rootval)
            {
                rootidxin = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootval);
        int leftlen = rootidxin-inst;
        int rightlen = ine-rootidxin;
        root->left = helper(pre,in,prest,prest+leftlen-1,inst,rootidxin-1,n);
        root->right = helper(pre,in,prest+leftlen,pree-1,rootidxin+1,ine,n);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in , vector<int>& post) {
        int n=post.size();
        return helper(post,in,0,n-1,0,n-1,n);
    }
};