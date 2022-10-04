class Solution {
public:
    
    int helper(int* dp,int n)
    {
        int* lefts = new int[n];
        int* rights = new int[n];
        
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                lefts[i] = 0;
                s.push(i);
            }
            else
            {
                int id = s.top();
                while(dp[id]>=dp[i])
                {
                    s.pop();
                    
                    if(s.empty())
                        break;
                    
                    id = s.top();
                }  
                if(s.empty())
                {
                    lefts[i]=0;
                    s.push(i);
                }
                else{
                    lefts[i] = s.top()+1;
                    s.push(i);
                }
            }
            //cout<<lefts[i]<<" ";
        }
        //cout<<endl;
        
        stack<int>s2;
        for(int i=n-1;i>=0;i--)
        {
            if(s2.empty())
            {
                rights[i] = n-1;
                s2.push(i);
            }
            else
            {
                int id = s2.top();
                while(dp[id]>=dp[i])
                {
                    s2.pop();
                    if(s2.empty())
                        break;
                    
                    id = s2.top();
                }  
                if(s2.empty())
                {
                    rights[i]=n-1;
                    s2.push(i);
                }
                else{
                    rights[i] = s2.top()-1;
                    s2.push(i);
                }
            }
            
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int res = (rights[i]-lefts[i]+1)*dp[i];
            mx = max(mx,res);
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int** dp=new int*[m];
        
        for(int i=0;i<m;i++)
            dp[i]=new int[n];
        
        for(int j=0;j<n;j++)
            dp[0][j]=(matrix[0][j]=='1')?1:0;
        
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(matrix[i][j]=='1')
                    dp[i][j]=dp[i-1][j]+1;
                
                else
                    dp[i][j]=0;
            }
        }
        /*for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int res = 0;
        for(int i=0;i<m;i++)
        {
            int ans = helper(dp[i],n);
            res = max(res,ans);
        }
        
        return res;
    }
};