// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
// 
// Return the maximum score you can get by erasing exactly one subarray.
// 
// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int N = nums.size();
        set<int> s;
        int ans = 0;
        for (int i = 0, j = 0, sum = 0; j < N; j++)
        {
            while (s.find(nums[j]) != s.end()) {
                s.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            s.insert(nums[j]);
            sum += nums[j];
            ans = max(ans, sum);
        }
        return ans;
    }
}; 
