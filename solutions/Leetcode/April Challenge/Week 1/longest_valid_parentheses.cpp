// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> open_stack;
        int ans = 0;
        int N = s.size();
        open_stack.push(-1);
        for (int  i = 0; i < N; i++) {
            char c = s[i];
            if (c == '(') {
                open_stack.push(i);
            }
            else {
                open_stack.pop();
                if (open_stack.empty()) {
                    open_stack.push(i);
                }
                else {
                    ans = max(ans, i - open_stack.top());
                }
            }
        }
        return ans;
    }
}; 
