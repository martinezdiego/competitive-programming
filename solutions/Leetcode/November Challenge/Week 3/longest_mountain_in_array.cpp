class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int N = arr.size();
        int L = 0, R = 0;
        int ans = 0;
        
        while (L < N) {
            R = L;
            if (R + 1 < N && arr[R] < arr[R + 1]) {
                while (R + 1 < N && arr[R] < arr[R + 1]) R++;
                if (R + 1 < N && arr[R] > arr[R + 1]) {
                    while (R + 1 < N && arr[R] > arr[R + 1]) R++;
                    ans = max(ans, R - L + 1);
                }
            }
            L = max(L + 1, R);
        }
        
        return ans;
    }
};
