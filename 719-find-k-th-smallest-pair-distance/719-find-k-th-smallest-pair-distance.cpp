class Solution {
public:
    
    bool helper(vector<int>nums,int mid,int k)
    {
        int n = nums.size();
        int cnt=0;
        int j=1;
        for(int i=0;i<n;i++)
        {
            while(j<n && nums[j]-nums[i]<=mid)
                j++;
            
            j--;
            cnt+=(j-i);
        }
        return (cnt>=k);
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxdiff = nums[n-1]-nums[0];
        int mindiff = 0;
        while(mindiff<maxdiff)
        {
            int mid = mindiff + (maxdiff-mindiff)/2;
            if(helper(nums,mid,k))
                maxdiff = mid;
            else
                mindiff = mid+1;
        }
        return maxdiff;
    }
};