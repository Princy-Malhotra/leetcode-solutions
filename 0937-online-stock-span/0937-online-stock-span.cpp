class StockSpanner {
public:
    stack<int>s;
    vector<int>v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        if(s.empty()){
            s.push(v.size()-1);
            return v.size();
        }
        else{
            while(!s.empty() && v[s.top()]<=price){
                s.pop();
            }
            if(s.empty())
            {
                s.push(v.size()-1);
                return v.size();
            }
            else{
                int id = s.top();
                s.push(v.size()-1);
                return v.size()-1-id;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */