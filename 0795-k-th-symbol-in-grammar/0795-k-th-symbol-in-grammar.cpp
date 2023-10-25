class Solution {
public:
    int help(int n, int k, int rootVal){
        if(n==1){
            return rootVal;
        }

        int numnodes = pow(2,n-1);
        if(k>numnodes/2){
            if(rootVal==0)
            return help(n-1,k-(numnodes/2),1);
            else{
                return help(n-1,k-(numnodes/2),0);
            }
        }
        else{
            if(rootVal==0)
            return help(n-1,k,0);
            else{
                return help(n-1,k,1);
            }
        }
    }
    int kthGrammar(int n, int k) {
        return help(n,k,0);
    }
};