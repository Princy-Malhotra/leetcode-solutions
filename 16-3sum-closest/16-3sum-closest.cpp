class Solution {
public:
    
    int help(vector<int>nums,int lo,int hi,int target)
    {
        
        while(lo<hi)
        {
            if(nums[lo]+nums[hi]>target)
            {
                if(hi-1==lo)
                    break;
                hi--;
            }
            else if(nums[lo]+nums[hi]<target)
            {
                if(lo+1==hi)
                    break;
                lo++;
            }
            
            else if(nums[lo]+nums[hi]==target)
                return target;
        }
        return (nums[lo]+nums[hi]);
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int hehe = INT_MAX;
        int ans;
        for(int i=0;i<n-2;i++)
        {
            int temp = nums[i];
            int nt = target-temp;
            
            int sa = help(nums,i+1,n-1,nt);
            sa = sa+temp;
            int absdiff = abs(sa-target);
            if(absdiff<hehe)
            {
                hehe=absdiff;
                ans=sa;
            }
        }
        return ans;
    }
};