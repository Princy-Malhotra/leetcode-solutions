class Solution {
public:
    int mod = 1000000007;
    vector<vector<int>>dp;
    int arrLen;
    int help(int steps, int st){
        if(steps==0){
            if(st==0){
                return 1;
            }
            return 0;
        }
        if(dp[st][steps]!=-1){
            return dp[st][steps];
        }
        int ans = help(steps-1,st);
        if(st>0){
            ans=(ans+help(steps-1,st-1)%mod)%mod;
        }
        if(st<this->arrLen-1){
            ans=(ans+help(steps-1,st+1)%mod)%mod;
        }
        return dp[st][steps]=ans%mod;
    }
    int numWays(int steps, int arrLen) {
        this->arrLen=min(arrLen,steps);
        dp.resize(this->arrLen,vector<int>(steps+1,-1));
        int ans = help(steps,0);
        return ans;
    }
};
