class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,pair<int,int>>>pq;
        vector<int>price(n,INT_MAX);
        vector<int>len(n,INT_MAX);
        int maxlen = k+2;
        len[src]=1;
        pq.push({0,{src,1}});
        price[src] = 0;
        while(!pq.empty()){
            auto t = pq.front();
            pq.pop();

            if(t.second.second>=maxlen)
            {
                price[t.second.first] = min(price[t.second.first],t.first);
                continue;
            }
            
            for(auto x:adj[t.second.first]){
                if(t.first+x.second<price[x.first]){
                    price[x.first] = t.first+x.second;
                    len[x.first] = t.second.second+1;
                    pq.push({price[x.first],{x.first,t.second.second+1}});
                }
                else if(t.second.second+1<len[x.first]){
                    pq.push({t.first+x.second,{x.first,t.second.second+1}});
                }
            }
        }
        if(price[dst]==INT_MAX)
        return -1;
        return price[dst];
    }
};