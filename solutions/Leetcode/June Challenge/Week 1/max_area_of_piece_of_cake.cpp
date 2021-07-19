// You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
// 
// horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 10^9 + 7.

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long maxH = max(horizontalCuts[0], h - horizontalCuts.back());
        long long maxW = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 0; i + 1 < (int)horizontalCuts.size(); i++) {
            maxH = max(maxH, (long long)horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for (int i = 0; i + 1 < (int)verticalCuts.size(); i++) {
            maxW = max(maxW, (long long)verticalCuts[i + 1] - verticalCuts[i]);
        }
        long long ans = (maxH*maxW);
        ans %= 1000000007;
        return (int)ans;
    }
}; 
