class Solution {
public:
    string decodeString(string s) {
        stack<int> num_stack;
        stack<string> str_stack;
        
        string str;
        int k = 0;
        
        for (char c : s)
        {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            }
            else if (c == '[') {
                str_stack.push(str);
                str = "";
                num_stack.push(k);
                k = 0;
            }
            else if (c == ']') {
                string tmp = str;
                str = str_stack.top();
                str_stack.pop();
                int count = num_stack.top();
                num_stack.pop();
                while (count--) str.append(tmp);
            }
            else {
                str.push_back(c);
            }
        }
        return str;
    }
};
