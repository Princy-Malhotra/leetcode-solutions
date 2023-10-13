class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int* dp = new int[n];
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];
        for(int i=n-3;i>=0;i--){
            dp[i] = min(cost[i]+dp[i+1],cost[i]+dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};