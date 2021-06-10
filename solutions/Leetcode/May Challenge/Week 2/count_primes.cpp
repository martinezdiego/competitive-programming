// Count the number of prime numbers less than a non-negative number, n.

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<bool> sieve(n + 1, 0);
        for (int i = 2; i < n; i++) {
            if (!sieve[i]) {
                sieve[i] = true;
                ans++;
                for (int x = i; x < n; x += i) {
                    sieve[x] = true; 
                }
            }
        }
        return ans;
    }
}; 
