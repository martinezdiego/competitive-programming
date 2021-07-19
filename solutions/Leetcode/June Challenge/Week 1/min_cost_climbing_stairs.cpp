// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
// 
// You can either start from the step with index 0, or the step with index 1.
// 
// Return the minimum cost to reach the top of the floor.

class Solution {
    vector<int> dp;
    int f(int floor, vector<int> & cost)
    {
        if (floor > cost.size())
            return 0;
        
        if (dp[floor] != -1)
            return dp[floor];
        
        int ans = cost[floor - 1];
        ans += min(f(floor + 1, cost), f(floor + 2, cost));
        
        return dp[floor] = ans;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        dp.assign(N + 1, - 1);
        int ans = 1e9;
        ans = f(1, cost);
        dp.assign(N + 1, - 1);
        ans = min(f(2, cost), ans);
        return ans;
    }
}; 
