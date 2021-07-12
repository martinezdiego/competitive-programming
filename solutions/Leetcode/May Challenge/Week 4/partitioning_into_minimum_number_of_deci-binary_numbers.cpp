// A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
// 
// Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

// Input: n = "32"
// Output: 3
// Explanation: 10 + 11 + 11 = 32

// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/discuss/970270/C%2B%2B-Python-Explanation-with-Image-and-Example-oror-Max-digit-oror-O(n)

class Solution {
public:
    int minPartitions(string n) {
        char ans = '$';
        for (char digit : n) {
            if (digit > ans) ans = digit;
        }
        return ans - '0';
    }
}; 
