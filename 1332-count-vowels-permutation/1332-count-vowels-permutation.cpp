class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        for(int i=0;i<5;i++){
            dp[1][i] = 1;
        }
        for(int i=2;i<=n;i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            dp[i][2] = ((dp[i-1][0] + dp[i-1][1])%mod + (dp[i-1][3] + dp[i-1][4])%mod)%mod;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4])%mod;
            dp[i][4] = dp[i-1][0];
        }
        return (((dp[n][0] + dp[n][1])%mod + dp[n][2])%mod + (dp[n][3] + dp[n][4])%mod)%mod;
    }
};