class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        vector<int> f1;
        vector<int> f2;
        for(auto x:flowers){
            f1.push_back(x[0]);
            f2.push_back(x[1]);
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        vector<int>ans;
        for(auto x:people){
            int startbloom = upper_bound(f1.begin(),f1.end(),x)-f1.begin();
            int stopbloom = lower_bound(f2.begin(),f2.end(),x)-f2.begin();
            ans.push_back(startbloom-stopbloom);
        }
        return ans;
    }
};