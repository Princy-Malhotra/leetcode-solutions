class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.size();
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(char ch='a';ch<='z';ch++)
        {
            if(mp.count(ch)==0)
                return false;
        }
        return true;
    }
};