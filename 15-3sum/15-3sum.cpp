class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*int n = nums.size();
        
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            int tarsum = -nums[i];
            
            /*if(mp[nums[i]])
                continue;
            
            mp[nums[i]]=1;*/
            
           /* vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if(j==i)
                    continue;
                
                else
                    temp.push_back(nums[j]);
            }*/
            /*
            int l = i+1;
            int r = nums.size()-1;
            //vector<int>v;
            
            while(l<r)
            {
                if(nums[l]+nums[r]==tarsum)
                {
                    /*v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);*/
                    /*if(mp[nums[l]]==0 || mp[nums[r]]==0)
                    {
                    //if(ans.find(v)!=ans.end())
                    ans.push_back({nums[i],nums[l],nums[r]});
                    mp[nums[l]]=1;
                    mp[nums[r]]=1;}
                    
                    l++;
                    r--;
                }
                
                else if(nums[l]+nums[r]<tarsum)
                {
                    l++;
                }
                
                else if(nums[l]+nums[r]>tarsum)
                    r--;
            }
        }
        return ans;*/
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
        if(i>0&& nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int >v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    j++;k--;
                    while(j<k &&nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
               else if(nums[i]+nums[j]+nums[k]>0)k--;
                else j++;
            }
        } 
       
        return ans;
    }
    
};