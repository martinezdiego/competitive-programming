class Solution {
public:
    // Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();
        int n1, n2;
        n1 = n2 = INT_MAX;
        for (int num : nums) {
            if (num <= n1) n1 = num;
            else if (num <= n2) n2 = num;
            else return true;
        }
        return false;
    }
};
