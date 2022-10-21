class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mp;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i])==0)
            {
                mp[nums[i]]=i;
            }
            else
            {
                if(abs(i-mp[nums[i]])<=k)
                {
                    return true;
                }
                mp[nums[i]]=i;
            }
        }
        return false;
    }
};