/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(MountainArray& arr, int st, int e){
        int lo=st;
        int hi=e;
        while(lo<hi-1){
            int mid = (lo+hi)/2;
            int midele = arr.get(mid);
            int prevele = arr.get(mid-1);
            int nextele = arr.get(mid+1);
            if(midele>prevele && midele>nextele){
                return mid;
            }
            else if(midele>prevele && midele<nextele){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        return -1;
    }
    int binSearch(MountainArray& arr, int st, int e, int order, int target){
        int lo=st,hi=e;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int midele = arr.get(mid);
            if(midele==target){
                return mid;
            }
            if(order==1){
                if(midele<target){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            else{
                if(midele<target){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peakidx = findpeak(mountainArr,0,n-1);
        //cout<<peakidx<<endl;
        int idx1 = binSearch(mountainArr,0,peakidx,1,target);
        if(idx1!=-1){
            return idx1;
        }
        int idx2 = binSearch(mountainArr,peakidx+1,n-1,2,target);
        if(idx2==-1) return -1;
        return idx2;
    }
};