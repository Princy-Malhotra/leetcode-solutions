class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(); 
        set<int>s;
        for(auto x:nums){
            s.insert(x);
        }
        vector<int>temp;
        for(auto x:s){
            temp.push_back(x);
        }
        int ans = n;
        for(int i=0;i<temp.size();i++){
            int left = temp[i];
            int right = left+n-1;
            int j = upper_bound(temp.begin(),temp.end(),right)-temp.begin();
            ans = min(ans,n-(j-i));
        }
        return ans;

    }
};