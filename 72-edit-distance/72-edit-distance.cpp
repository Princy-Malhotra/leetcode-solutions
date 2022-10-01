class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        int** dp = new int*[m+1];
        for(int i=0;i<=m;i++)
        {
            dp[i]=new int[n+1];
        }
        
        dp[0][0]=0;
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=j;
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[m-i]!=word2[n-j])
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                else
                    dp[i][j]=dp[i-1][j-1];
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return dp[m][n];
    }
};