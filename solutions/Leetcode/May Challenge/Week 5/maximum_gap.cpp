// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
// 
// You must write an algorithm that runs in linear time and uses linear extra space.

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 1) return 0;
        int maxE = *max_element(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());
        int a = maxE - minE;
        int b = n - 1;
        int len = (a + b - 1)/b;
        if (len == 0) len++;
        vector<int> maxA(n,INT_MIN);
        vector<int> minA(n,INT_MAX);
        for(int i=0; i<n; i++) {
            int index = (nums[i]-minE)/len;
            maxA[index] = max(maxA[index],nums[i]);
            minA[index] = min(minA[index],nums[i]);
        }
        
        int gap = 0, prev = maxA[0];
        for(int i=1; i<n; i++) {
            if(minA[i]==INT_MAX) continue;
            gap = max(gap,minA[i]-prev);
            prev = maxA[i];
        }
        return gap;
    }
}; 
