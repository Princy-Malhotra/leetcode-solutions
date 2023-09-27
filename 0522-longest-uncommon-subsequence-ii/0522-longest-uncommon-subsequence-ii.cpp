class Solution {
public:
    bool isSubseq(string a, string b){
        if(a.length()==0){
            return true;
        }
        if(a.length()>b.length()){
            return false;
        }
        int i=0;
        int n=b.length();
        while(i<n && b[i]!=a[0]){
            i++;
        }
        if(i==n){
            return false;
        }
        return isSubseq(a.substr(1),b.substr(i+1));
    }
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int>mp;
        vector<pair<int,string>>v;
        for(auto x:strs){
            mp[x]++;
            v.push_back({x.length(),x});
        }
        sort(v.rbegin(),v.rend());
        
        int n=v.size();
        for(int i=0;i<n;i++){
            if(mp[v[i].second]>1){
                continue;
            }
            else{
                int p=0;
                for(int j=0;j<i;j++){
                    if(isSubseq(v[i].second,v[j].second))
                    {
                        p=1;
                        break;
                    }
                }
                if(p==0){
                    return v[i].first;
                }
            }
        }
        return -1;
    }
};