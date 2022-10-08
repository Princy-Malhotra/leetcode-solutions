class MyCalendar {
public:
    set<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(v.empty())
        {
            v.insert({start,end});
            return true;
        }
        
        int n = v.size();
        auto nextele = v.lower_bound({start,end});
        if(nextele!=v.end())
        {
            if(nextele->first<end)
                return false;
        }
        
        if(nextele!=v.begin())
        {
            auto prevele = prev(nextele);
            if(prevele->second>start)
                return false;
        }
        
        v.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */