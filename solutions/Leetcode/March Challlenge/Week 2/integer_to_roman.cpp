/*
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
 */

class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbol = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        vector<int> val = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string ans;
        int i = 0;
        while (i < 13)
        {
            if (num >= val[i]) {
                ans += symbol[i];
                num -= val[i];
            }
            else {
                i++;
            }
        }
        return ans;
    }
};
