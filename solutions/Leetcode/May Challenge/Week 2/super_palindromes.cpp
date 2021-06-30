// Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
// 
// Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].
// left and right represent integers in the range [1, 10^18 - 1].

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        int ans = 0;
        // create palindromes in range 1, 10^5
        // even palindromes
        for (int i = 1; i < 100000; i++) {
            string num = to_string(i);
            for (int j = num.size() - 1; j >= 0; j--) {
                num.push_back(num[j]);
            }
            long long n = stoll(num);
            n *= n;
            if (n > r) break;
            if (n >= l && is_palindrome(n)) ans++;
        }
        // odd palindromes
        for (int i = 1; i < 100000; i++) {
            string num = to_string(i);
            for (int j = num.size() - 2; j >= 0; j--) {
                num.push_back(num[j]);
            }
            long long n = stoll(num);
            n *= n;
            if (n > r) break;
            if (n >= l && is_palindrome(n)) ans++;
        }
        return ans;
    }
    
    bool is_palindrome(long long n)
    {
        return n == reverse(n);
    }
    
    long long reverse(long long n)
    {
        long long num = 0;
        while (n > 0) {
            num = num*10 + n%10;
            n /= 10;
        }
        return num;
    }
}; 
