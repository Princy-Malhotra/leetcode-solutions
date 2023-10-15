// class Solution {
// public:
//     int mod = 1000000007;
//     vector<vector<int>>dp;
//     int arrLen;
//     int help(int steps, int st){
//         if(steps==0){
//             if(st==0){
//                 return 1;
//             }
//             return 0;
//         }
//         if(dp[st][steps]!=-1){
//             return dp[st][steps];
//         }
//         int ans = help(steps-1,st)%mod;
//         if(st>0){
//             ans=(ans+help(steps-1,st-1)%mod)%mod;
//         }
//         if(st<this->arrLen-1){
//             ans=(ans+help(steps-1,st+1)%mod)%mod;
//         }
//         return dp[st][steps]=ans%mod;
//     }
//     int numWays(int steps, int arrLen) {
//         dp.resize(arrLen,vector<int>(steps+1,-1));
//         this->arrLen=min(arrLen,steps);
//         int ans = help(steps,0);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> memo;
    int MOD = 1e9 + 7;
    int arrLen;
    
    int dp(int curr, int remain) {
        if (remain == 0) {
            if (curr == 0) {
                return 1;
            }
            
            return 0;
        }
        
        if (memo[curr][remain] != -1) {
            return memo[curr][remain];
        }

        int ans = dp(curr, remain - 1);
        if (curr > 0) {
            ans = (ans + dp(curr - 1, remain - 1)) % MOD;
        }
        
        if (curr < arrLen - 1) {
            ans = (ans + dp(curr + 1, remain - 1)) % MOD;
        }
        
        memo[curr][remain] = ans;
        return ans;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        this->arrLen = arrLen;
        memo = vector(arrLen, vector(steps + 1, -1));
        return dp(0, steps);
    }
};