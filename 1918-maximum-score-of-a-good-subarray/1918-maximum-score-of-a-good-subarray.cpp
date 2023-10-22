class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        // int ans = nums[k];
        // int currpro = nums[k];
        // priority_queue<int,vector<int>,greater<int>>pq;
        // pq.push(nums[k]);
        // int i=k,j=k;
        // while(i!=0 && j!=n-1){
        //         if(nums[i-1]>nums[j+1]){
        //             i--;
        //             pq.push(nums[i]);
        //             currpro = (pq.top())*(j-i+1);
        //             ans = max(ans,currpro);
        //         }
        //         else{
        //             j++;
        //             pq.push(nums[j]);
        //             currpro = (pq.top())*(j-i+1);
        //             ans = max(ans,currpro);
        //         }    
        // }
        // while(i!=0){
        //     i--;
        //     pq.push(nums[i]);
        //     currpro = (pq.top())*(j-i+1);
        //     ans = max(ans,currpro);
        // }
        // while(j!=n-1){
        //     j++;
        //     pq.push(nums[j]);
        //     currpro = pq.top()*(j-i+1);
        //     ans = max(ans,currpro);
        // }
        // return ans;
        int ans = nums[k];
        int currpro = nums[k];
        stack<int>s;
        int i=k,j=k;
        s.push(nums[k]);
        while(i!=0 && j!=n-1){
            if(nums[i-1]>nums[j+1]){
                i--;
                if(s.empty()){
                    s.push(nums[i]);
                    currpro = nums[i] * (j-i+1);
                }
                else{
                    while(!s.empty() && s.top()>nums[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        s.push(nums[i]);
                    }
                    currpro = s.top() * (j-i+1);
                }
                ans = max(ans,currpro);
            }
            else{
                j++;
                if(s.empty()){
                    s.push(nums[j]);
                    currpro = nums[j]*(j-i+1);
                }
                else{
                    while(!s.empty() && s.top()>nums[j]){
                        s.pop();
                    }
                    if(s.empty()){
                        s.push(nums[j]);
                    }
                    currpro = s.top() * (j-i+1);
                }
                ans = max(ans,currpro);
            }
        }
        while(i!=0){
            i--;
            if(s.empty()){
                s.push(nums[i]);
                currpro = nums[i] * (j-i+1);
            }
            else{
                while(!s.empty() && s.top()>nums[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(nums[i]);
                }
                currpro = s.top() * (j-i+1);
            }
            ans = max(ans,currpro);
        }
        while(j!=n-1){
            j++;
            if(s.empty()){
                s.push(nums[j]);
                currpro = nums[j]*(j-i+1);
            }
            else{
                while(!s.empty() && s.top()>nums[j]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(nums[j]);
                }
                currpro = s.top() * (j-i+1);
            }
            ans = max(ans,currpro);
        }
        return ans;
    }
};