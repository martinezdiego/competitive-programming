class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if (N <= 2) {
            return N;
        }
        int l = 1;
        int r = 2;
        while (r < N)  {
            if (!(nums[r] == nums[l] and nums[l] == nums[l - 1])) {
                l++;
                nums[l] = nums[r];
            } 
            r++;
        }
        return l + 1;
    }
}; 
