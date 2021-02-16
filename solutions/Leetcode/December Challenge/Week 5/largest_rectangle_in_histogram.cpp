class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        stack<int> s;
        int i = 0;
        long long ans = 0;
        while (i < N)
        {
            if (s.empty() or heights[s.top()] <= heights[i]) {
                s.push(i++);
            }
            else {
                int tp = s.top();
                s.pop();
                long long area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                ans = max(ans, area);
            }
        }
        while (!s.empty())
        {
            int tp = s.top();
            s.pop();
            long long area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            ans = max(ans, area);
        }
        return ans;
    }
};
