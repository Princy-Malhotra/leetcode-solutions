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
    unordered_map<int,vector<int>>mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL){
            return v;
        }
        map<pair<int,int>,multiset<int>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>temp = q.front();
            q.pop();
            mp[temp.second].insert(temp.first->val);
            if(temp.first->left){
                q.push({temp.first->left,{temp.second.first+1,temp.second.second-1}});
            }
            if(temp.first->right){
                q.push({temp.first->right,{temp.second.first+1,temp.second.second+1}});
            }
        }
        map<int,vector<int>>ans;
        for(auto x:mp){
            for(auto y:x.second){
                ans[x.first.second].push_back(y);
            }
        }
    
        for(auto x:ans){
            v.push_back(x.second);
        }
        return v;

    }
};