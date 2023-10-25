class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dest) {
        vector<double>dist(n,0);
        dist[src]=1;
        for(int i=0;i<n-1;i++){
            bool check = true;
            for(int j=0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                if(dist[v]<dist[u]*succProb[j]){
                    dist[v] = dist[u]*succProb[j];
                    check=false;
                }
                if(dist[u]<dist[v]*succProb[j]){
                    dist[u] = dist[v]*succProb[j];
                    check=false;
                }
            }
            if(check)
            break;
        }
        return dist[dest];
    }
};