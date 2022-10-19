class Solution {
public:
    
    static bool cmp(pair<int,string>a,pair<int,string>b)
    {
        if(a.first<b.first)
        return true;

        if(a.first>b.first)
        return false;

        else
        return a.second>b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        vector<pair<int,string>>v;
        for(auto i: mp)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.rbegin(),v.rend(),cmp);
        vector<string>ans;
        int n1 = v.size();
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};