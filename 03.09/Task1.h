#ifndef TASK1_H
#define TASK1_H

#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    vector<vector<int>> FromAdjacencyListToMatrix(vector<vector<int>> list, int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i{0}; i < list.size(); ++i)
        {
            for (int j{0}; j < list[i].size(); ++j)
            {
                matrix[i][list[i][j]] = 1;
            }
        }
        return matrix;
    }

    vector<vector<int>> FromMatrixToAdjacencyList(vector<vector<int>> matrix, int n)
    {
        vector<vector<int>> list(n);
        for (int i{0}; i < matrix.size(); ++i)
        {
            for (int j{0}; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j])
                    list[i].push_back(j);
            }
        }
        return list;
    }

    vector<vector<int>> FromEdgeListToAdjacencyList(vector<pair<int, int>> EdgeList, int n)
    {
        vector<vector<int>> AdjacencyList(n);
        for (auto i : EdgeList)
        {
            AdjacencyList[i.first].push_back(i.second);
        }
        return AdjacencyList;
    }

    vector<pair<int, int>> FromAdjacencyListToEdgeList(vector<vector<int>> AdjacencyList, int n)
    {
        vector<pair<int, int>> EdgeList;
        for (int i{0}; i < AdjacencyList.size(); ++i)
        {
            for (auto j : AdjacencyList[i])
            {
                EdgeList.push_back(make_pair(i, j));
            }
        }
        return EdgeList;
    }

    vector<vector<int>> FromEdgeListToAdjacencyMatrix(vector<pair<int, int>> EdgeList, int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        for (auto i : EdgeList)
        {
            matrix[i.first][i.second] = 1;
        }
        return matrix;
    }

    vector<pair<int, int>> FromAdjacencyMatrixToEdgeList(vector<vector<int>> matrix, int n)
    {
        vector<pair<int, int>> EdgeList;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (matrix[i][j])
                    EdgeList.push_back(make_pair(i, j));
            }
        }
        return EdgeList;
    }
};

#endif /* TASK1_H */