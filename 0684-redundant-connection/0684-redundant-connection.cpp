class Solution {
public:
    void dfs(vector<vector<int>>& adj, int src, unordered_map<int,int>& vis){
        vis[src]=1;
        for(auto x:adj[src]){
            if(!vis[x]){
                dfs(adj,x,vis);
            }
        }
        return;
    }
    bool help(vector<vector<int>>& adj, int src, int dest){
        unordered_map<int,int>vis;
        dfs(adj,src,vis);
        if(!vis[dest]){
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        vector<int>ans(2);
        for(auto x:edges){
            int src = x[0] - 1;
            int dest = x[1] - 1;
            bool t = help(adj,src,dest);
            if(t){
                adj[x[0]-1].push_back(x[1]-1);
                adj[x[1]-1].push_back(x[0]-1);
            }
            else{
                ans[0] = x[0];
                ans[1] = x[1];
            }
        }
        return ans;
    }
};