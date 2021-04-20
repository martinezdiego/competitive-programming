/*
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.
 */

class Solution {
private:
    int f(int amount, const vector<int> & coins, vector<int> & dp)
    {
        if (amount == 0)
            return 0;
        
        if (dp[amount] != -1)
            return dp[amount];
        
        int ans = 1e7;
        
        for (int coin : coins) {
            if (amount >= coin) {
                ans = min(ans, f(amount - coin, coins, dp) + 1);
            }
        }
        
        return dp[amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10005, -1);
        int ans = f(amount, coins, dp);
        return (ans < 1e7 ? ans : -1);
    }
};
