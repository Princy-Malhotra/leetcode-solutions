class TopVotedCandidate {
public:
    vector<int>p;
    vector<int>ti;
    vector<int>lead;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        p=persons;
        ti=times;
        int n=persons.size();
        int maxv=0;
        int leadper;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[p[i]]++;
            if(mp[p[i]]>=maxv){
                maxv=mp[p[i]];
                leadper=p[i];
            }
            lead.push_back(leadper);
        }
    }
    
    int q(int t) {
        int idx = upper_bound(ti.begin(),ti.end(),t)-ti.begin();
        idx--;
        return lead[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */