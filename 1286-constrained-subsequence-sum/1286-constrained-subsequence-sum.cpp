class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n);
        // dp[n-1] = nums[n-1];
        // int ans = dp[n-1];
        // priority_queue<pair<int,int>>pq;
        // pq.push({nums[n-1],n-1});
        // for(int i=n-2;i>=0;i--){
        //     int t;
        //     while(!pq.empty() && pq.top().second>min(i+k,n-1)){
        //         pq.pop();
        //     }
        //     t = pq.top().first;
        //     dp[i] = max(nums[i]+t,nums[i]);
        //     ans = max(dp[i],ans);
        //     pq.push({dp[i],i});
        // }
        // return ans;
        deque<int>q;
        dp[0] = nums[0];
        int ans = dp[0];
        if(dp[0]>0){
            q.push_back(0);
        }
        for(int i=1;i<n;i++){
            while(!q.empty() && i-q.front()>k){
                q.pop_front();
            }
            dp[i] = (!q.empty()?dp[q.front()]+nums[i]:nums[i]);
            ans = max(ans, dp[i]);
            while(!q.empty() && dp[q.back()]<dp[i]){
                q.pop_back();
            }
            if(dp[i]>0)
            q.push_back(i);
        }
        return ans;
    }
};