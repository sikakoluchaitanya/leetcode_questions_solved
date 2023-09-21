/*You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 */
 
 class Solution {
public:
    bool isPossible(vector<vector<int>>& heights, int mid) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto &dir : directions) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;

                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && !visited[new_x][new_y] && abs(heights[new_x][new_y] - heights[x][y]) <= mid) {
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                }
            }
        }

        return visited[rows - 1][cols - 1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0;
        int right = 1e6;  // Initialize the binary search range.

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isPossible(heights, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
