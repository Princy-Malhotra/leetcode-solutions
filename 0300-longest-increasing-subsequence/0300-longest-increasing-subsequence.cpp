class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int* dp = new int[n];
        for(int i=0;i<n;i++)
        {
                dp[i]=1;
        }
        int res=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            res = max(res,dp[i]);
        }
        
        return res;
    }
};