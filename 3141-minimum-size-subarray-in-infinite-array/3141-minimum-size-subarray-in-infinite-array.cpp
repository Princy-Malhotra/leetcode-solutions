class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();
        long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int ans = target/sum;
        target = target%sum;
        if(target==0){
            return ans*n;
        }
        unordered_map<long,int>mp;
        mp[0] = -1;
        long s=0,res=(long)n;
        for(long i=0;i<2*n;i++){
            s+=nums[i%n];
            if(mp.count(s-target)){
                res = min(res,i-mp[s-target]);
            }
            mp[s] = i;
        }
        if(res==n)
        return -1;
        return res+(ans*n);

    }
};