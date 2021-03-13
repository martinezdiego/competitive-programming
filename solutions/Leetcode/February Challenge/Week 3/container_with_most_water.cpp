class Solution {
public:
    int maxArea(vector<int>& height) {
        long long ans = 0;
        int N = height.size();
        int start = 0, end = N-1;
        while (start < end)
        {
            long long area = (end - start) * (min(height[start], height[end]));
            ans = max(ans, area);
            if (height[start] < height[end]) start++;
            else end--;
        }
        return ans;
    }
};
