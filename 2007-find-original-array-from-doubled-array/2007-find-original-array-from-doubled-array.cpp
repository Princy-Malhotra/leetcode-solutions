class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        int n = changed.size();
        
        //int* vis = new int[n];
        map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[changed[i]]++;
        
        //sort(changed.begin(),changed.end());
        set<int>s;
        for(int i=0;i<n;i++)
            s.insert(changed[i]);
        vector<int>res;
        
        if(mp[0]%2!=0)
            return res;
        
        else
        {
            for(int j=0;j<mp[0]/2;j++)
                ans.push_back(0);
        }
        
        for(auto x:s)
        {
            if(mp[x] && x!=0)
            {
                    if(mp[x*2]>=mp[x])
                    {
                        for(int j=0;j<mp[x];j++)
                        ans.push_back(x);
                        mp[x*2]-=mp[x];
                    }
                    else{
                        return res;
                    }
                
                mp[x]=0;
            }
        }
        return ans;
    }
};