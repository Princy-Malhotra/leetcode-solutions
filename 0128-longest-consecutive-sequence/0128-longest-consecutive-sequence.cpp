const long long mex = 1000000001;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        // if(n==0)
        // return 0;
        // if(n==1)
        // return 1;
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        // int ans=1;
        // for(int i=0;i<n;i++){
        //     if(s.find(nums[i]-1)!=s.end()){
        //         continue;
        //     }
        //     else{
        //         int cnt=1;
        //         for(int j=nums[i]+1;j<mex;j++){
        //             if(s.find(j)!=s.end())
        //             cnt++;
        //             else{
        //                 break;
        //             }
        //         }
        //     ans = max(ans,cnt);

        //     }
        // }
        // return ans;
        int prev=-1000000001;
        int cnt=0;
        int ans = 0;
        for(auto x:s){
            if(prev==-1000000001){
                prev=x;
                cnt++;
            }
            else{
                if(x==prev+1){
                    cnt++;
                }
                else{
                    ans=max(cnt,ans);
                    cnt=1;
                }
                prev=x;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};