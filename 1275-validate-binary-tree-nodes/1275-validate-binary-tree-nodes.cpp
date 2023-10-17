class Solution {
public:
    void dfs(vector<int>& leftchild, vector<int>& rightchild, int src, int n, unordered_map<int,int>& vis){
        vis[src]=1;
        if(leftchild[src]==-1 && rightchild[src]==-1){
            return;
        }

        if(leftchild[src]!=-1 && !vis[leftchild[src]])
        dfs(leftchild,rightchild,leftchild[src],n,vis);
        if(rightchild[src]!=-1 && !vis[rightchild[src]])
        dfs(leftchild,rightchild,rightchild[src],n,vis);
        return;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftchild, vector<int>& rightchild) {
        unordered_map<int,int>indeg;
        for(int i=0;i<n;i++){
            if(leftchild[i]!=-1){
                indeg[leftchild[i]]++;
            }
            if(rightchild[i]!=-1){
                indeg[rightchild[i]]++;
            }
        }
        int p=0;
        int rootnode;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                p++;
                rootnode=i;
            }
            if(indeg[i]>=2){
                return false;
            }
        }
        if(p!=1){
            return false;
        }
        unordered_map<int,int>vis;
        dfs(leftchild,rightchild,rootnode,n,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;

    }
};