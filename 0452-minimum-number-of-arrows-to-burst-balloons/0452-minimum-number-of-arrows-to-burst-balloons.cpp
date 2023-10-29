class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // greedy
        // at least 1 arrow
        int ans = 1;
        // sort by end to cover more balloons
        sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y) {
           return x[1] < y[1]; 
        });
        // init cur_end with the first balloon
        int cur_end = points[0][1];
        for (auto p : points) {
            int l = p[0], r = p[1];
            // if cur_end < new_start
            if (cur_end < l) {
                // then we need a new arrow
                ans += 1;
                // update cur_end
                cur_end = r;
            }
        }
        return ans;
    }
};