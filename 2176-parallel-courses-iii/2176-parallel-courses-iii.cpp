class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,int>indeg;
        vector<vector<int>>adj(n+1);
        vector<int>maxtime(n+1,0);
        for(auto x:relations){
            indeg[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
                maxtime[i] = time[i-1];
            }
        }
        //q.push(-1);
        //int mx=0;
        int ans=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans = max(maxtime[t],ans);
            for(auto x:adj[t]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
                maxtime[x] = max(maxtime[x],maxtime[t]+time[x-1]);
            }
        }
        return ans;
    }
};