class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        vector<int>v;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                v.push_back(cnt);
                cnt=1;
            }
        }
        v.push_back(cnt);
        int n1 = v.size();
        int ans=0;
        for(int i=0;i<n1-1;i++){
            ans+=min(v[i],v[i+1]);
        }
        return ans;
    }
};