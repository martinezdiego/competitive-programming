class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        int open = 0;
        int N = S.size();
        stack<int> layer;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == '(') {
                open++;
            }
            else {
                open--;
            }  
            
            if (S[i] == ')' and S[i -1] == '(') {
                ans += (1 << open);
            }
        }
        // int cnt = 0;
        // for (char c : S)
        // {
        //     if (c == '(') {
        //         layer.push(cnt);
        //         cnt = 0;
        //     }
        //     else {
        //         if (cnt == 0) cnt = layer.top() + 1;
        //         else cnt = 2 * cnt + layer.top();
        //         layer.pop();
        //     }
        // }
        // return cnt;
        return ans;
    }
}; 
