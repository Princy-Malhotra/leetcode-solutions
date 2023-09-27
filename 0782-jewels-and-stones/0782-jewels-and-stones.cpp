class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>j;
        int ans=0;
        for(auto x:jewels){
            j[x]++;
        }
        for(auto x:stones){
            if(j.count(x)){
                ans++;
            }
        }
        return ans;
    }
};