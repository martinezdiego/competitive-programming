// A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
// 
// For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
// In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
// A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
// 
// Given an integer array nums, return the length of the longest wiggle subsequence of nums.

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        if (N < 2) {
            return N;
        }
        for (int i = 0; i + 1 < N; i++) {
            int len = (nums[i + 1] - nums[i] != 0 ? 2 : 1);
            int positive = nums[i + 1] - nums[i] > 0;
            for (int j = i + 1; j + 1 < N; j++) {
                int cur = nums[j + 1] - nums[j];
                if (positive and cur < 0) {
                    positive = !positive;
                    len++;
                }
                else if (!positive and cur > 0) {
                    positive = !positive;
                    len++;
                }
            }
            ans =max(ans, len);
        }
    return ans;
    }
};
