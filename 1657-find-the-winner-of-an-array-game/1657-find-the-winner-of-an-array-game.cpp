class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>n){
            int mex = 0;
            for(auto x:arr){
                mex=max(mex,x);
            }
            return mex;
        }
        else{
            unordered_map<int,int>mp;
            int t = arr[0]>arr[1]?arr[0]:arr[1];
            mp[t]++;
            if(mp[t]>=k){
                return t;
            }
            for(int i=2;i<n;i++){
                t = max(t,arr[i]);
                mp[t]++;
                if(mp[t]>=k){
                    return t;
                }
            }
            return t;
        }
    }
};