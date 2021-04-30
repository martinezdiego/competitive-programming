// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
// 
// As the answer can be very large, return it modulo 10^9 + 7.

// Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (arr[i], arr[j], arr[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = 1000000007;
        long long ans = 0;
        int N = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < N; i++)
        {
            int T = target - arr[i];
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                if (arr[j] + arr[k] < T) {
                    j++;
                }
                else if (arr[j] + arr[k] > T) {
                    k--;
                }
                else if (arr[j] != arr[k]) {
                    int l = 1;
                    int r = 1;
                    while (j + 1 < k and arr[j] == arr[j + 1]) {
                        l++;
                        j++;
                    }
                    while (k - 1 > j and arr[k] == arr[k - 1]) {
                        r++;
                        k--;
                    }
                    ans += l * r;
                    ans %= MOD;
                    j++;
                    k--;
                }
                else {
                    ans += (k - j + 1)* (k - j)/ 2;
                    ans %= MOD;
                    break;
                }
            }
        }
        return (int) ans;
    }
}; 
