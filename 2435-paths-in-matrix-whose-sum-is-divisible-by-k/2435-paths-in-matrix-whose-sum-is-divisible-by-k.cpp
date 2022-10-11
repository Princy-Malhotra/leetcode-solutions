const long long mod = 1000000007;

class Solution {
public:
    /*int cnt=0;
    int helper(vector<vector<int>>grid,int sum,int k,int i,int j,int m,int n)
    {
        if(i>=m || j>=n)
            return;
        
        if(i==m-1 && j==n-1)
        {
            if((sum+grid[i][j])%k==0)
            {
                cnt++;
                return;
            }
            
            return;
        }
        
        helper(grid,sum+grid[i][j],k,i+1,j,m,n);
        helper(grid,sum+grid[i][j],k,i,j+1,m,n);
        return;
    }*/
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j] = grid[i][j]%k;
            }
        }
        int*** dp = new int**[m];
        for(int i=0;i<m;i++)
        {
            dp[i]=new int*[n];
            for(int j=0;j<n;j++)
            {
                dp[i][j]=new int[k];
                for(int y=0;y<k;y++)
                {
                    dp[i][j][y]=0;
                }
            }
            
        }
        
        for(int i=0;i<k;i++)
        {
            if(i==grid[m-1][n-1])
                dp[m-1][n-1][i]=1;
            
            else
                dp[m-1][n-1][i]=0;
        }
        
        /*for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<k;j++)
            {
                if(dp[m-1][i+1][j]==0)
                    continue;
                
                int newrem = (j+grid[m-1][i])%k;
                dp[m-1][i][newrem]=dp[m-1][i+1][j];
                //cout<<dp[m-1][i][newrem]<<" ";
            }
            //cout<<endl;
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<k;j++)
            {
                if(dp[i+1][n-1][j]==0)
                    continue;
                
                int newrem = (j+grid[i][n-1])%k;
                dp[i][n-1][newrem]=dp[i+1][n-1][j];
                //cout<<dp[i][n-1][newrem]<<" ";
            }
            //cout<<endl;
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                for(int y=0;y<k;y++)
                {
                    int kk = (y+grid[i][j])%k;
                    dp[i][j][kk] = ((dp[i+1][j][y]%mod) + (dp[i][j+1][y]%mod))%mod;
                }
            }
        }
        
        //int rem=0;
        //helper(grid,rem,k,0,0,m,n,dp);
        return dp[0][0][0];
        //return 0;
    }
};