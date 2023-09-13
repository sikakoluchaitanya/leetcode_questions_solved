/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.*/

int candy(int* ratings, int ratingsSize)
{
    int* candies = (int*)malloc(sizeof(int) * ratingsSize);
    int sum = 0;

    // Initialize each child with 1 candy
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;
    }

    // Scan from left to right and ensure higher ratings get more candies than left neighbors
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Scan from right to left and update if needed to ensure higher ratings get more candies than right neighbors
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    // Calculate the total number of candies needed
    for (int i = 0; i < ratingsSize; i++) {
        sum += candies[i];
    }

    free(candies);
    return sum;
}


