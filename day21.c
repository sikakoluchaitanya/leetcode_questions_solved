/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.*/


int customComparator(const void* a, const void* b) {
    int* rowA = *(int**)a;
    int* rowB = *(int**)b;
    
    // Count the number of soldiers (1's) in each row
    int countA = 0, countB = 0;
    for (int i = 0; i < rowA[0]; i++) {
        countA += rowA[i + 1];
        countB += rowB[i + 1];
    }
    
    // Compare rows based on the number of soldiers and row index
    if (countA != countB) {
        return countA - countB;
    }
    
    return rowA[rowA[0] + 1] - rowB[rowB[0] + 1];
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    // Allocate memory for an array of pointers to rows
    int** rows = (int**)malloc(matSize * sizeof(int*));
    
    for (int i = 0; i < matSize; i++) {
        // Allocate memory for each row
        rows[i] = (int*)malloc((matColSize[0] + 2) * sizeof(int));
        
        // Store the number of soldiers (1's) at the beginning
        rows[i][0] = matColSize[0];
        
        // Copy the row data and row index
        for (int j = 0; j < matColSize[0]; j++) {
            rows[i][j + 1] = mat[i][j];
        }
        rows[i][matColSize[0] + 1] = i; // Store the row index at the end
    }
    
    // Sort the rows using custom comparator
    qsort(rows, matSize, sizeof(int*), customComparator);
    
    // Create the result array and populate it with the row indices
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = rows[i][matColSize[0] + 1]; // Get the row index
    }
    
    // Set the return size
    *returnSize = k;
    
    // Free allocated memory
    for (int i = 0; i < matSize; i++) {
        free(rows[i]);
    }
    free(rows);
    
    return result;
}
