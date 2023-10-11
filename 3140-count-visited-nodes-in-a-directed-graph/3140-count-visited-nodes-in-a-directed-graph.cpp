class Solution {
public:
    int dfs(vector<int>& edges, int src, unordered_map<int,int>&vis){
        if(vis[src]){
            return 0;
        }
        vis[src] = 1;
        
        int cnt=1;
        cnt+=dfs(edges,edges[src],vis);
        return cnt;
        
        
    }
    // int markCyclicNodes(vector<int>& edges, int src, unordered_map<int,int>& vis, unordered_map<int,int>&partofCyc){
    //     if(vis[src] && !partofCyc[src]){
    //         partofCyc[src]=1;
    //         return 1;
    //     }
    //     if(vis[src] && partofCyc[src]){
    //         return 0;
    //     }
        
    //     vis[src]=1;
    //     int ans = 
        
    // }
    int help(vector<int>& edges,int src, vector<int>&v, unordered_map<int,int>&vis){
        if(vis[src]){
            return 0;
        }
        vis[src]=1;
        v.push_back(src);
        return 1+help(edges,edges[src],v,vis);
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        //vector<int>dp(n,-1);
        unordered_map<int,int>vis;
        vector<int>res(n);
        unordered_map<int,int>indeg;
        for(auto x:edges){
            indeg[x]++;
        }
        queue<int>q;
        stack<int>s;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                s.push(i);
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            vis[t]=1;
            indeg[edges[t]]--;
            if(!indeg[edges[t]])
            {
                q.push(edges[t]);
                s.push(edges[t]);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>v;
                int cyclen = help(edges,i,v,vis);
                for(auto x:v){
                    res[x]=cyclen;
                }
            }
        }
        while(!s.empty()){
            int t=s.top();
            s.pop();
            res[t] = 1+res[edges[t]];
        }
        return res;
    }
};