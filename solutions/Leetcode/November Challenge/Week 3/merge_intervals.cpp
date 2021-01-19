class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int cur_min = intervals[0][0];
        int cur_max = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= cur_max) {
                cur_max = max(cur_max, intervals[i][1]);
            } 
           else {
               ans.push_back({cur_min, cur_max});
               cur_min = intervals[i][0];
               cur_max = intervals[i][1];
            }
        }
        ans.push_back({cur_min, cur_max});
        return ans;
    }
};
