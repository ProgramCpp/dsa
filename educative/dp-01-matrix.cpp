// #include<climits>

// // param d - direction// dont parse direction you're coming from
// // 0 - all directions
// // 1 - not left
// // 2 - not up
// // 3 - not right
// // 4 - not down
// int findMinD(vector<vector<int>> &mat, vector<vector<int>> &matD, int i, int j, int d){
//     if (i < 0 || i == mat.size() || j < 0 || j == mat[0].size())
//         return INT_MAX;

//     if(matD[i][j] != INT_MAX)
//         return matD[i][j];

//     if (mat[i][j] == 0){
//         matD[i][j] = 0;
//         return 0;
//     }

//     if (d != 3)
//         matD[i][j] = min(matD[i][j], findMinD(mat, matD, i, j + 1, 1));
//     if (d != 1)
//         matD[i][j] = min(matD[i][j], findMinD(mat, matD, i, j - 1, 3));
//     if (d != 4)
//         matD[i][j] = min(matD[i][j], findMinD(mat, matD, i + 1, j, 2));
//     if (d != 2)
//         matD[i][j] = min(matD[i][j], findMinD(mat, matD, i - 1, j, 4));

//     return matD[i][j];
// }

// std::vector<std::vector<int>> UpdateMatrix(std::vector<std::vector<int>> mat) {
//     int m = mat.size();
//     int n = mat[0].size();
//     vector<vector<int>> matD(m, vector<int>(n,INT_MAX));

//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n ; j++){
//             matD[i][j] = findMinD(mat, matD, i, j, 0);
//         }

//     return matD;
// }


#include <climits>

std::vector<std::vector<int>> UpdateMatrix(std::vector<std::vector<int>> mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> minD(m, vector<int>(n, INT_MAX));

    for(int i = 0; i <m; i++){
        for(int j = 0; j < n; j++){
            if (mat[i][j] == 0)
                minD[i][j] = 0;
            else{
                int minij = INT_MAX;
                if (i -1 >= 0)
                    minij = minD[i - 1][j];
                if (j -1 >= 0)
                    minij = min(minij, minD[i][j-1]);
                if (minij != INT_MAX)
                    minD[i][j] = 1 + minij;
            }
        }
    }

    for(int i = m -1; i >=0; i--){
        for(int j = n -1; j >= 0; j--){
            if (mat[i][j] == 0)
                minD[i][j] = 0;
            else{
                int minij = INT_MAX;
                if (i + 1 < m)
                    minij = min(minij, minD[i + 1][j]);
                if (j + 1 < n)
                    minij = min(minij, minD[i][j+1]);
                if (minij != INT_MAX && minij < minD[i][j])
                    // add 1 only if min is coming from adjacent cells
                    // if the cell already has min, there is no need to assign
                    // even if assigned, it must be cell value. not cell value + 1
                    minD[i][j] = 1 + minij;
            }
        }
    }

    return minD;
}

