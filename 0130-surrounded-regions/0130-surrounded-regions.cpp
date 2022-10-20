class Solution {
public:
    bool** flip;
    int** vis;
    void dfs(vector<vector<char>>& board,int m,int n,int i,int j)
    {
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!='O' || vis[i][j]==1)
            return;
        
        flip[i][j]=false;
        vis[i][j]=1;
        
        dfs(board,m,n,i-1,j);
        dfs(board,m,n,i+1,j);
        dfs(board,m,n,i,j-1);
        dfs(board,m,n,i,j+1);
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vis = new int*[m];
        flip = new bool*[m];
        for(int i=0;i<m;i++)
        {
            vis[i]=new int[n];
            flip[i]=new bool[n];
            for(int j=0;j<n;j++)
            {
                vis[i][j]=0;
                
                if(board[i][j]=='X')
                    vis[i][j]=1;
                
                if(i==0 || i==m-1 || j==0 || j==n-1)
                    flip[i][j]=false;
                else
                    flip[i][j]=true;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board,m,n,i,0);
            }
            
            if(board[i][n-1]=='O')
            {
                dfs(board,m,n,i,n-1);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
            {
                dfs(board,m,n,0,i);
            }
            
            if(board[m-1][i]=='O')
            {
                dfs(board,m,n,m-1,i);
            }
        }
        
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && flip[i][j]==true)
                {
                    board[i][j]='X';
                }
            }
        }
        //return board;
    }
};