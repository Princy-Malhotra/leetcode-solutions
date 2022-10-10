class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int fi = arr[0];
        int se = arr[1];
        int mindif = se-fi;
        for(int i=1;i<n-1;i++)
        {
            fi = arr[i];
            se = arr[i+1];
            
            if(se-fi<mindif)
                mindif = se-fi;
        }
        
        vector<vector<int>>v;
        for(int i=0;i<n-1;i++)
        {
            fi = arr[i];
            se = arr[i+1];
            if(se-fi==mindif)
            {
                v.push_back({arr[i],arr[i+1]});
            }
        }
        return v;
    }
};