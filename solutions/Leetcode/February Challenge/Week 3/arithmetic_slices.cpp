class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        int N = A.size();
        if (N < 3) {
            return 0;
        }
        for (int k = 3; k <= N; k++) {
            for (int i = 0; i + k - 1 < N; i++) {
                int dif = A[i + 1] - A[i];
                bool ok = true;
                for (int j = i; j < i + k - 1; j++) {
                    int curdif = A[j + 1] - A[j];
                    if (curdif != dif) {
                        ok = false;
                        break;
                    }
                } 
                if (ok) ans++;
            }
        }
        return ans;
    }
};
