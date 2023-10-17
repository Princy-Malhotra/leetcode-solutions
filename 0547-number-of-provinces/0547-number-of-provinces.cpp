class Solution {
public:
    void dfs(vector<vector<int>>& isCon, int src, unordered_map<int,int>& vis){
        vis[src]=1;
        int n=isCon.size();

        for(int i=0;i<n;i++){
            if(isCon[src][i] && !vis[i]){
                dfs(isCon,i,vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        int n=isCon.size();
        unordered_map<int,int>vis;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(isCon,i,vis);
            }
        }
        return cnt;
    }
};