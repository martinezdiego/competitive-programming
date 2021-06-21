// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
// 
// In one move, you can increment or decrement an element of the array by 1.
// 
// Test cases are designed so that the answer will fit in a 32-bit integer

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int mid = (N%2 == 0 ? (N+1)/2 : N/2);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += abs(nums[i] - nums[mid]);
        }
        return ans;
    }
}; 
