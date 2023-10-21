class Solution {
public:
    vector<vector<int>> help(vector<vector<pair<int,char>>>& adj, int src, int n){
        queue<pair<int,pair<int,char>>>q;
        q.push({src,{0,'b'}});
        q.push({src,{0,'r'}});
        vector<vector<int>>dist(n,vector<int>(2,INT_MAX));          // 0==> blue    1==> red
        map<pair<int,char>,int>vis;
        dist[src][0] = 0;
        dist[src][1] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            vis[{t.first,t.second.second}]=1;
            for(auto x:adj[t.first]){
                if(t.first==x.first){
                    if(x.second==t.second.second){
                        char ch = (x.second=='r')?'b':'r';
                        if(!vis[{x.first,ch}])
                        q.push({x.first,{t.second.first+1,ch}});
                    }
                    continue;
                }
                else{
                    if(t.second.second==x.second){
                        char ch = (x.second=='r')?'b':'r';
                        int chin = (ch=='b')?0:1;
                        if(dist[x.first][chin]>t.second.first+1){
                        q.push({x.first,{t.second.first+1,ch}});
                        dist[x.first][chin] = t.second.first+1;
                        }
                    }
                }
            }
        }
        return dist;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)  {
        vector<vector<pair<int,char>>>adj(n);
        for(auto x:redEdges){
            adj[x[0]].push_back({x[1],'r'});
        }
        for(auto x:blueEdges){
            adj[x[0]].push_back({x[1],'b'});
        }
        vector<vector<int>>ans = help(adj,0,n);
        vector<int>res(n);
        res[0]=0;
        for(int i=1;i<ans.size();i++){
            if(ans[i][0]==INT_MAX && ans[i][1]==INT_MAX){
                res[i]=-1;
            }
            else{
                res[i] = min(ans[i][0],ans[i][1]);
            }
        }
        return res;
    }
};