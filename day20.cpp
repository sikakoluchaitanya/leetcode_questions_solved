/*
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
 

Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        
        int n = graph.size();
        if (n == 1) return 0;

        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Initialize the queue with all nodes as starting points
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = 0;
            q.push({1 << i, i});
        }

        while (!q.empty()) {
            auto [mask, u] = q.front();
            q.pop();

            for (int v : graph[u]) {
                int new_mask = mask | (1 << v);
                if (dp[new_mask][v] == -1) {
                    dp[new_mask][v] = dp[mask][u] + 1;
                    q.push({new_mask, v});
                }
            }
        }

        int shortest = INT_MAX;
        for (int i = 0; i < n; ++i) {
            shortest = min(shortest, dp[(1 << n) - 1][i]);
        }

        return shortest;
    }
    
};
