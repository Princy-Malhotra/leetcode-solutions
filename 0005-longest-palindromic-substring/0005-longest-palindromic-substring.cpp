class Solution {
public:
    bool isPalindrome(string str,int st,int e)
    {
        while(st<=e)
        {
            if(str[st]!=str[e])
                return false;
            st++;
            e--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        bool** dp=new bool*[n];
        for(int i=0;i<n;i++)
            dp[i]=new bool[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=true;
                if(i>j)
                    dp[i][j]=true;
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i<j)
                {
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1];
                    else
                        dp[i][j]=false;
                }
            }
        }
        int ans=0,st;
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i<=j && dp[i][j]==true)
                {
                    if(j-i+1>ans)
                    {
                        st=i;
                        ans = j-i+1;
                    }
                }
            }
        }
        return s.substr(st,ans);
    }
};