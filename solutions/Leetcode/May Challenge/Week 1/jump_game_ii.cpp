// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// 
// Each element in the array represents your maximum jump length at that position.
// 
// Your goal is to reach the last index in the minimum number of jumps.
// 
// You can assume that you can always reach the last index.
// 
// Input: nums = [2,3,1,1,4]
// Output: 2

class Solution {
    vector<int> dp;
    int f(int i, vector<int> & nums)
    {
        int N = nums.size();
        if (i >= N - 1) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        int ans = f(i + 1, nums) + 1; 
        if (nums[i] > 0) {
            for (int k = 1; k <= nums[i]; k++) {
                ans = min(ans, f(i + k, nums) + 1);       
            }
        }
        return dp[i] = ans;
    }
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        dp.assign(N, -1);
        return f(0, nums);
    }
}; 
