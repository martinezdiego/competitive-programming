// Given two integers n and k, construct a list answer that contains n different positive integers ranging from 1 to n and obeys the following requirement:
// 
// Suppose this list is answer = [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
// Return the list answer. If there multiple valid answers, return any of them.

// Input: n = 3, k = 2
// Output: [1,3,2]
// Explanation: The [1,3,2] has three different positive integers ranging from 1 to 3, and the [2,1] has exactly 2 distinct integers: 1 and 2.

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int l = 1, r = k + 1;
        for (int i = 0; i < k + 1; i++) {
            if (i%2 == 0) ans.push_back(l++);
            else ans.push_back(r--);
        }
        for (int i = k + 2; i <= n; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};
