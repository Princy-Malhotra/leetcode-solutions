class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
        return false;
        double y = log2(n)/2;
        if((long long)y == y){
            return true;
        }
        return false;
    }
};