class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        map<pair<pair<int,int>,int>,int>vis;
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{0,0},{k,1}});
        vis[{{0,0},k}]=1;
        vector<pair<int,int>> dx = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            pair<pair<int,int>,pair<int,int>> p = q.front();
            q.pop();
            int x = p.first.first;
            int y = p.first.second;
            if(x==m-1 && y==n-1){
                return p.second.second-1;
            }
            for(auto t:dx){
                if(x+t.first>=0 && x+t.first<m && y+t.second>=0 && y+t.second<n && grid[x+t.first][y+t.second]==1){
                    if(p.second.first>=1 && !vis[{{x+t.first,y+t.second},p.second.first-1}]){
                    q.push({{x+t.first,y+t.second},{p.second.first-1,p.second.second+1}});
                    vis[{{x+t.first,y+t.second},p.second.first-1}]=1;
                    }
                }
                else if(x+t.first>=0 && x+t.first<m && y+t.second>=0 && y+t.second<n && grid[x+t.first][y+t.second]==0 && vis[{{x+t.first,y+t.second},p.second.first}]==0){
                    q.push({{x+t.first,y+t.second},{p.second.first,p.second.second+1}});
                    vis[{{x+t.first,y+t.second},p.second.first}]=1;
                }
            }

        }
        return -1;

    }
};