class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
        vector<int>pmin(n);
        pmin[0] = nums[0];
        for(int i=1;i<n;i++){
            pmin[i] = min(pmin[i-1],nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>pmin[i]){
                if(s.empty()){
                    s.push(nums[i]);
                }
                else{
                    while(!s.empty() && s.top()<=pmin[i]){
                        s.pop();
                    }
                    if(!s.empty() && s.top()>pmin[i] && s.top()<nums[i]){
                        return true;
                    }
                    else{
                        s.push(nums[i]);
                    }
                }
            }
        }
        return false;
    }
};