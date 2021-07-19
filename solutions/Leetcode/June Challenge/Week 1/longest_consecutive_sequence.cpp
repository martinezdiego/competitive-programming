// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// 
// You must write an algorithm that runs in O(n) time.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num : nums) seen[num] = 1;
        int ans = 0;
        for (const pair<int, int> & p : seen) {
            int num = p.first;
            if (seen.find(num - 1) == seen.end()) {
                int cur = 1;
                while (seen.find(num + 1) != seen.end()) {
                    num++;
                    cur++;
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
}; 
