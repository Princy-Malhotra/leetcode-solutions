class TimeMap {
public:
    map<pair<string,int>,string>mp;
    set<pair<string,int>>s;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[{key,timestamp}] = value;
        pair<string,int>p;
        p.first = key;
        p.second = timestamp;
        s.insert(p);
    }
    
    string get(string key, int timestamp) {
        if(mp.count({key,timestamp})==0)
        {
            if(mp.size()==0)
                return "";
            
            int temp=INT_MIN;
            int p=0;
            auto itr = s.lower_bound({key,timestamp});
            /*for(auto x:mp)
            {
                if(x.first.first==key && x.first.second<timestamp)
                {
                    p=1;
                    if(x.first.second>temp)
                    {
                        temp = x.first.second;
                    }
                }
            }*/
            if(itr==s.begin())
                return "";
            itr--;
            if(itr->first!=key)
                return "";
            return mp[*itr];
        }
        return mp[{key,timestamp}];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */