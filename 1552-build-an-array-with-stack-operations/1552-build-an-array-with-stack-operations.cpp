class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_map<int,int>mp;
        int mx = INT_MIN;
        for(auto x:target){
            mp[x]++;
            mx=max(mx,x);
        }
        stack<int>s;
        vector<string>ans;
        for(int i=1;i<=n;i++){
            if(i>mx){
                break;
            }
            if(mp.count(i)){
                while(!s.empty()){
                    if(!mp.count(s.top()))
                    {
                        s.pop();
                        ans.push_back("Pop");
                    }
                    else{
                        break;
                    }
                }
                s.push(i);
                ans.push_back("Push");
            }
            else{
                s.push(i);
                ans.push_back("Push");
            }
        }
        return ans;
    }
};