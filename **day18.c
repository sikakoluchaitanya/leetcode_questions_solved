/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
*/

// Define a structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Define the comparison function for sorting edges by weight
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find the parent of a node in the disjoint-set data structure
int findParent(int parent[], int node) {
    if (parent[node] == -1)
        return node;
    return findParent(parent, parent[node]);
}

// Union operation for disjoint-set data structure
void unionSets(int parent[], int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    if (xSet != ySet) {
        parent[xSet] = ySet;
    }
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    // Calculate the total number of edges
    int numEdges = pointsSize * (pointsSize - 1) / 2;
    struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));

    if (!edges) {
        // Handle memory allocation error
        return -1;
    }

    int edgeIndex = 0;

    // Compute Manhattan distances and store them as edges
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges[edgeIndex].src = i;
            edges[edgeIndex].dest = j;
            edges[edgeIndex].weight = distance;
            edgeIndex++;
        }
    }

    // Sort the edges by weight
    qsort(edges, numEdges, sizeof(struct Edge), compare);

    // Initialize the parent array for the disjoint-set data structure
    int parent[pointsSize];
    for (int i = 0; i < pointsSize; i++) {
        parent[i] = -1;
    }

    int minCost = 0;

    // Apply Kruskal's algorithm to find the minimum spanning tree
    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        int srcParent = findParent(parent, src);
        int destParent = findParent(parent, dest);

        if (srcParent != destParent) {
            unionSets(parent, srcParent, destParent);
            minCost += edges[i].weight;
        }
    }

    // Free dynamically allocated memory
    free(edges);

    return minCost;
}

