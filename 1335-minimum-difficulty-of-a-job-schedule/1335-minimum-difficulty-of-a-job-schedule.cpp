class Solution {
public:
    //int cost=0;
    int helper(vector<int>jd,int d,int mx,int st)
    {
        int n=jd.size();
        if(d==0)
        {
            return INT_MAX;
        }
            
        if(st==n-1)
        {
            if(d>1)
                return INT_MAX;
            
            if(jd[st]>mx)
            {
                return jd[st];
            }
            return mx;
        }
        int temp = mx;
        if(jd[st]>mx)
        {
            mx=jd[st];            
        }
        int cost=0;
        int sa1 = helper(jd,d-1,0,st+1);
        int sa2 = helper(jd,d,mx,st+1);
        
        if(sa1!=INT_MAX && sa2!=INT_MAX)
        return min(sa1+mx,sa2);
        
        if(sa1!=INT_MAX || sa2!=INT_MAX)
        return min(sa1,sa2);
        
        return mx;
    }
    
    int helper2(vector<int>&jd,int d,int n,int idx,int** dp)
    {
        if(d==1)
        {
            return *max_element(jd.begin()+idx,jd.end());
        }
        
        if(dp[idx][d]!=-1)
            return dp[idx][d];
        
        int mx = INT_MIN;
        int res = INT_MAX;
        for(int i=idx;i<=n-d;i++)
        {
            mx = max(mx,jd[i]);
            res = min(res,mx+helper2(jd,d-1,n,i+1,dp));
        }
        dp[idx][d]=res;
        return res;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        //return helper(jd,d,0,0);
        int n=jd.size();
        if(n<d)
            return -1;
        int**dp=new int*[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[d+1];
            for(int j=0;j<=d;j++)
            {
                dp[i][j]=-1;
            }
        }
        return helper2(jd,d,n,0,dp);
        
        
        /*int* pref=new int[n];
        pref[0]=jd[0];
        if(n==d)
        {
            //int sum=0;
            for(int i=1;i<n;i++)
            {
                pref[i]=jd[i]+pref[i-1];
            }
            return pref[n-1];
        }
        
        int** dp = new int*[n];
        int* mx = new int[d];
        for(int i=0;i<d;i++)
            mx[i]=INT_MIN;
        for(int i=0;i<n;i++)
        {
            dp[i]=new int[d];
            for(int j=0;j<d;j++)
            {
                if(i<j)
                    dp[i][j]=-1;
                else if(i==j)
                {
                    dp[i][j] = pref[i];
                    mx[j]=max(mx[j],jd[i]);
                }
            }
        }
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<d;j++)
            {
                if(i==j || i<j)
                    continue;
                
                if(mx[j]==INT_MIN)
                    mx[j]=jd[i];
                
                
            }
        }*/
        
    }
};