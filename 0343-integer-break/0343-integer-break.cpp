class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,INT_MIN);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        if(n>2)
        dp[3] = 2;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=(i-j);j++){
                dp[i] = max(dp[i],max(dp[j]*dp[i-j],max(j*(i-j),max(dp[j]*(i-j),j*dp[i-j]))));
            }
        }
        return dp[n];
    }
};