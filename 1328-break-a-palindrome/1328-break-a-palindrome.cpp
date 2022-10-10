class Solution {
public:
    string breakPalindrome(string p) {
        if(p.length()==1)
            return "";
        
        int n = p.length();
        int cnt=0;
        int id=-1;
        for(int i=0;i<n;i++)
        {
            if(p[i]=='a')
                cnt++;
            
            else{
                id = i;
            }
        }
        if(cnt==n)
        {
            p[n-1]='b';
            return p;
        } 
        
        if(n%2!=0 && cnt==n-1)
        {
            if(id==n/2)
            {
                p[n-1]='b';
                return p;
            }
        }
        
        int i=0;
        while(p[i]=='a')
            i++;
        
        //if(n%2==0 || i!=n/2)
        //
            p[i]='a';
            return p;
        //
        
    }
};