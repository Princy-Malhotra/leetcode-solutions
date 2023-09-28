class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        list<int>l;
        for(auto x:nums){
            if(x%2==0){
                l.push_front(x);
            }
            else{
                l.push_back(x);
            }
        }
        vector<int>v;
        while(!l.empty()){
            v.push_back(l.front());
            l.pop_front();
        }
        return v;
    }
};