class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int N = A.size();
        sort(A.begin(), A.end());
        int ans = A[N - 1] - A[0];
        for (int i = 0; i + 1 < N; i++) {
            int high = max(A[N - 1] - K, A[i] + K);
            int low = min(A[0] + K, A[i + 1] - K);
            ans = min(ans, high - low);
        }
        return ans;
    }
};
