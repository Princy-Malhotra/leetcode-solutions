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
    unordered_map<TreeNode*, pair<int,int>>mp;
    void sumofsubtree(TreeNode* root){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            mp[root] = {root->val,1};
            return;
        }
        int sum=root->val;
        int cnt=1;
        if(root->left){
            sumofsubtree(root->left);
            sum+=mp[root->left].first;
            cnt+=mp[root->left].second;
        }
        if(root->right){
            sumofsubtree(root->right);
            sum+=mp[root->right].first;
            cnt+=mp[root->right].second;
        }
        mp[root] = {sum,cnt};
        return;
    }
    int help(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        int la=0,ra=0;
        if(root->left){
            la = help(root->left);
        }
        if(root->right){
            ra = help(root->right);
        }
        int ans = la+ra;
        if(root->val==mp[root].first/mp[root].second){
            ans++;
        }
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        sumofsubtree(root);
        return help(root);
    }
};