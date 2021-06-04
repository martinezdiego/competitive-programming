// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
// 
// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
// 
// Input: nums = [4,2,3]
// Output: true

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int pos = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) cnt++, pos = i;
            if (cnt == 2) return false;
        }
        if (pos > 0) {    
            int ret = nums[pos];
            nums[pos] = nums[pos - 1];
            bool ok = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                ok = true;
                nums[pos] = ret;
                nums[pos - 1] = nums[pos];
                for (int i = 1; i < nums.size(); i++) {
                    if (nums[i] < nums[i - 1]) {
                        ok = false;
                        break;
                    }
                }
            }
            return ok;
        }
        return true;
    }
}; 
