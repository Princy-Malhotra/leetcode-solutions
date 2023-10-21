class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        dp[n-1] = nums[n-1];
        int ans = dp[n-1];
        priority_queue<pair<int,int>>pq;
        pq.push({nums[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            int t;
            while(!pq.empty() && pq.top().second>min(i+k,n-1)){
                pq.pop();
            }
            t = pq.top().first;
            dp[i] = max(nums[i]+t,nums[i]);
            ans = max(dp[i],ans);
            pq.push({dp[i],i});
        }
        return ans;

    }
};