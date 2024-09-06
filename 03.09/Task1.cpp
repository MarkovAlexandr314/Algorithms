#include <vector>

using namespace std;

vector<vector<int>> FromListToMatrix(vector<vector<int>> list, int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i{0}; i < list.size(); ++i)
    {
        for (int j{0}; j < list[i].size(); ++j)
        {
            matrix[i][j] = 1;
        }
    }
    return matrix;
}

vector<vector<int>> FromMatrixToList(vector<vector<int>> matrix, int n)
{
    vector<vector<int>> list(n, vector<int>(n));
    for (int i{0}; i < matrix.size(); ++i)
    {
        for (int j{0}; j < matrix[i].size(); ++j)
        {
            if (list[i][j])
                list[i].push_back(j);
        }
    }
    return list;
}