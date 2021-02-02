class Solution {
public:
    // find how many A[i] + B[j] + C[k] + D[l] == 0
    // total time complexity: O(2N^2) = O(N^2)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> mp;
        int N = A.size();
        int ans = 0;
        // A[i] + B[j] = - (C[k] + D[l])
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int s  = A[i] + B[j];
                mp[s]++;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int s = C[i] + D[j];
                if (mp.find(-1 * s) != mp.end())
                    ans += mp[-1 * s];
            }
        }
        return ans;
    }
};
