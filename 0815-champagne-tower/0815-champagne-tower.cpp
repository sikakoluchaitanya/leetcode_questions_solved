class Solution {
public:
    
double champagneTower(int poured, int query_row, int query_glass) {
    std::vector<std::vector<double>> tower(query_row + 1, std::vector<double>(query_row + 1, 0.0));
    tower[0][0] = static_cast<double>(poured);

    for (int i = 0; i < query_row; ++i) {
        for (int j = 0; j <= i; ++j) {
            double excess = (tower[i][j] - 1.0) / 2.0;
            if (excess > 0) {
                tower[i + 1][j] += excess;
                tower[i + 1][j + 1] += excess;
            }
        }
    }

    return std::min(1.0, tower[query_row][query_glass]);
}

};