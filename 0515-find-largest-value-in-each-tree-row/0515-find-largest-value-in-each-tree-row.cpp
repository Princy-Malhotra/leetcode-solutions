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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int res = INT_MIN;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t==NULL){
                ans.push_back(res);
                res = INT_MIN;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                res = max(res,t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
        }
        return ans;
    }
};