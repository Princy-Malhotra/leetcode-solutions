class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=0;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        // queue<int>q;
        // q.push(k);
        //unordered_map<int,int>vis;
        vector<int>time(n+1,INT_MAX);
        // time[k] = 0;
        // while(!q.empty()){
        //     int t = q.front();
        //     q.pop();
        //     vis[t]=1;
        //     for(auto x:adj[t]){
        //         if(!vis[x.first])
        //         q.push(x.first);
        //         time[x.first] = min(time[x.first],time[t]+x.second);

        //     }
        // }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});
        time[k]=0;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            for(auto x:adj[t.second]){
                if(time[t.second]+x.second<time[x.first]){
                time[x.first] = time[t.second]+x.second;
                pq.push({time[x.first],x.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX){
                return -1;
            }
            ans = max(ans, time[i]);
        }
        return ans;

    }
};