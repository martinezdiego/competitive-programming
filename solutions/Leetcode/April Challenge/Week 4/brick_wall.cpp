// There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.
// 
// Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
// 
// Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
// 
// Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
// Output: 2

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int N = wall.size();
        map<int, int> brick_edges;
        int max_brick_edges = 0;
        for (int i = 0; i < N; i++) {
            int edge_idx = 0;
            int M = wall[i].size();
            for (int j = 0; j < M - 1; j++) {
                edge_idx += wall[i][j];
                brick_edges[edge_idx]++;
                max_brick_edges = max(max_brick_edges, brick_edges[edge_idx]);
            }
        }
        return N - max_brick_edges;
    }
}; 
