class Solution {
private:
    string remove_whites(const string & source) {
        string s;
        for (char c : source) {
            if (c != ' ') s.push_back(c);
        }
        return s;
    }
public:
    int calculate(string s) {
        s = remove_whites(s);
        int cur = 0;
        int n = s.size();
        char op = '+';
        stack<int> num_stack;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            
            if (isdigit(c))
            {
                cur = cur * 10 + (c - '0');
            }
            if (not isdigit(c) or i == n - 1)
            {
                if (op == '+') {
                    num_stack.push(cur);
                }
                else if (op == '-') {
                    num_stack.push(-cur);
                }
                else if (op == '*') {
                    int prev = num_stack.top();
                    num_stack.pop();
                    num_stack.push(prev * cur);
                }
                else {
                    int prev = num_stack.top();
                    num_stack.pop();
                    num_stack.push(prev / cur);
                }
                op = c;
                cur = 0;
            }
        }
        int ans = 0;
        while (not num_stack.empty()) {
            ans += num_stack.top();
            num_stack.pop();
        }
        return ans;
    }
};
