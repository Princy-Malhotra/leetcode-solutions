class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j] = 1;
        if(i==0 || i==m-1 || j==0 || j==n-1)
        return false;

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        bool a = true;
        for(int k=0;k<4;k++){
            if(!vis[i+dx[k]][j+dy[k]] && grid[i+dx[k]][j+dy[k]]==0){
                vis[i+dx[k]][j+dy[k]]=1;
                bool b=dfs(grid,i+dx[k],j+dy[k],vis);
                if(!b)
                a=false;
            }
        }
        return a;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    if(dfs(grid,i,j,vis))
                    cnt++;
                }
            }
        }
        return cnt;
    }
};