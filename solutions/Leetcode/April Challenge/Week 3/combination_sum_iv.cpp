// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
// 
// The answer is guaranteed to fit in a 32-bit integer.
// 
// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.

class Solution {
    vector<int> dp;
    
    int solve(vector<int> & nums, int target)
    {
        if (target == 0)
            return 1;
        
        if (dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for (int num : nums) {
            if (target - num >= 0)
                ans += solve(nums, target - num);
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, - 1);
        return solve(nums, target);
    }
};
