class DSU{
public:
    int n;
    vector<int>parent;
    DSU(int n){
        this->n = n;
        parent.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        while(parent[x]!=x){
            x = parent[x];
        }
        return x;
    }
    void unionxy(int x,int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1==p2){
            return;
        }
        else{
            if(p1<p2){
                parent[p2] = p1;
            }
            else{
                parent[p1] = p2;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        vector<int>ans(2);
        DSU dsu(n);
        for(auto x:edges){
            if(dsu.find(x[0])==dsu.find(x[1])){
                ans[0] = x[0];
                ans[1] = x[1];
            }
            else
            dsu.unionxy(x[0],x[1]);
        }
        return ans;
    }
};