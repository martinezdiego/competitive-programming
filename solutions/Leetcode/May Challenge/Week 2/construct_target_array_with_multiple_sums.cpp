// You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
// 
// let x be the sum of all elements currently in your array.
// choose index i, such that 0 <= i < n and set the value of arr at index i to x.
// You may repeat this procedure as many times as needed.
// Return true if it is possible to construct the target array from arr, otherwise, return false.

// Input: target = [9,3,5]
// Output: true
// Explanation: Start with arr = [1, 1, 1] 
// [1, 1, 1], sum = 3 choose index 1
// [1, 3, 1], sum = 5 choose index 2
// [1, 3, 5], sum = 9 choose index 0
// [9, 3, 5] Done

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for (int val : target) {
            sum += val;
            pq.push(val);
        }
        while (!pq.empty() and pq.top() > 1) {
            int top = pq.top();
            pq.pop();
            sum -= top;
            if (top - sum <= 0 or sum < 1) return false;
            top %= sum;
            sum += top;
            pq.push(top ? top : sum);
        }
        return true;
    }
}; 
