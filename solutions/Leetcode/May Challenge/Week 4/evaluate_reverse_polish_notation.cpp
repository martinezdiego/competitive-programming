// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// 
// Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
// 
// Note that division between two integers should truncate toward zero.
// 
// It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string & token : tokens)
        {
            if (isdigit(token[0]) or token.size() > 1) {
                nums.push(stoi(token));
            }
            else {
                int op2 = nums.top(); nums.pop();
                int op1 = nums.top(); nums.pop();
                if (token == "+") op1 += op2;
                if (token == "-") op1 -= op2;
                if (token == "*") op1 *= op2;
                if (token == "/") op1 /= op2;
                nums.push(op1);
            }
        }
        return nums.top();
    }
}; 
