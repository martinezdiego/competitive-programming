class Solution {
public:
    // bottom up DP
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        int A[N + 2];
        A[0] = A[N + 1] = 1;
        for (int i = 1; i <= N; i++) {
            A[i] = nums[i - 1];
        }
        int dp[N + 2][N + 2];
        memset(dp, 0, sizeof dp);
        for (int len = 1; len <= N; len++) {
            for (int start = 1; start < N - len + 2; start++) {
                int end = start + len - 1;
                for (int last = start; last <= end; last++) {
                    dp[start][end] = max(dp[start][end], 
                                         dp[start][last - 1] + A[start - 1] * A[last] * A[end + 1] + dp[last + 1][end]);
                }
            }
        }
        return dp[1][N];
    }
    
    // recursive aproach
    int maxCoinsRec(vector<int>& nums) {
        int N = nums.size();
        vector<int> A(N + 2);
        A[0] = A[N + 1] = 1;
        for (int i = 1; i <= N; i++) {
            A[i] = nums[i - 1];
        }
        return maxCoinRecUtil(A);
    }
    
    int maxCoinRecUtil(vector<int> A) {
        int N = A.size();
        if (N == 2) {
            return 0;
        }
        int mx = 0;
        for (int start = 1; start < N - 1; start++) {
            int val = A[start - 1] * A[start] * A[start + 1] + maxCoinRecUtil(formNewArray(A, start));
            mx = max(mx, val);
        }
        return mx;
    }
    
    vector<int> formNewArray(vector<int> A, int dontIncludeIndex)
    {
        int N = A.size();
        vector<int> newA;
        for (int i = 0; i < N; i++) {
            if (i != dontIncludeIndex) newA.push_back(A[i]);
        }
        return newA;
    }
};
