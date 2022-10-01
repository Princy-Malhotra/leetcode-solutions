class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int* dp = new int[n+1];
        if(n==1)
        {
            if(s[0]!='0')
                return 1;
            else
                return 0;
        }
        dp[0]=1;
        dp[1]=(s[n-1]=='0')?0:1;
        for(int i=2;i<=n;i++)
        {
            if(s[n-i]!='0')
            {
                dp[i] = dp[i-1];
                string temp = string(1,s[n-i]) + s[n-i+1];
                int num = stoi(temp);
                if(num<=26)
                dp[i]+=dp[i-2];
            }
            else{
                if(i==n)
                    return 0;
                
                if(s[n-i-1]=='0')
                    return 0;
                
                dp[i]=0;
            }
        }
        return dp[n];
    }
};