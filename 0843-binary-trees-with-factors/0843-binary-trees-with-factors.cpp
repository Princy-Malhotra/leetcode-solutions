class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>dp(n,1);
        dp[0] = 1;
        int ans=1;
        for(int i=1;i<n;i++){
            int l=0;
            int r=i-1;
            while(l<=r){
                if((long long)arr[l]*(long long)arr[r]==(long long)arr[i]){
                    if(l==r){
                        dp[i]=(dp[i]+(((long long)dp[l]*dp[r])%mod))%mod;
                        break;
                    }
                    else{
                        int t = (2*(((long long)dp[l]*dp[r])%mod))%mod;
                        dp[i]=(dp[i]+t)%mod;
                        l++;
                        r--;
                    }
                }
                else if((long long)arr[l]*(long long)arr[r]>(long long)arr[i]){
                    r--;
                }
                else if((long long)arr[l]*(long long)arr[r]<(long long)arr[i]){
                    l++;
                }
            }
            ans=(ans+(dp[i]%mod))%mod;
        }
        return ans;
    }
};