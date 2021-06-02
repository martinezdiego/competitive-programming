class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty()) {
            return ans;
        }
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        cout << l << ' ' << r << endl;
        if (l == nums.size() or r == 0) {
            return ans;
        }
        if (nums[r - 1] == target) ans[1] = r - 1;
        if (nums[l] == target) ans[0] = l;
        return ans;
    }
}; 
