class Solution {
public:
    string say(string s)
    {
        int n=s.length();
        int cnt=1;
        char ch=s[0];
        string out="";
        unordered_map<char,int>mp;
        for(int i=1;i<n;i++)
        {
            if(s[i]==ch)
            {
                cnt++;
                mp[ch]=cnt;
            }
            else{
                if(cnt!=0)
                {
                    int x = cnt;
                    int y = ch-48;
                    int num = x*10 + y;
                    string temp = to_string(num);
                    out+=temp;
                }
                cnt=1;
                ch=s[i];
            }
        }
        if(cnt!=0)
        {
              int x = cnt;
              int y = ch-48;
              int num = x*10 + y;
              string temp = to_string(num);
              out+=temp;
        }
        return out;
    }
    string countAndSay(int n) {
        string* dp=new string[n+1];
        dp[1]="1";
        dp[2]="11";
        dp[3]="21";
        cout<<say(dp[3])<<endl;
        for(int i=4;i<=n;i++)
        {
            dp[i]=say(dp[i-1]);
        }
        return dp[n];
    }
};