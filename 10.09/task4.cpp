#include <vector>
#include <functional>

using namespace std;

class Solution
{
    vector<vector<int>> FromMatrixToAdjacencyList(vector<vector<int>> matrix)
    {
        vector<vector<int>> list(matrix.size());
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

    vector<int> weak_comp(const vector<vector<int>> &g)
    {
        vector<int> comp_idx(g.size(), -1);
        int cur_idx = 0;

        function<void(int)> dfs = [&](int v)
        {
            comp_idx[v] = cur_idx;
            for (int u : g[v])
                if (comp_idx[u] == -1)
                    dfs(u);
        };

        for (size_t v = 0; v < g.size(); v++)
        {
            if (comp_idx[v] == -1)
            {
                dfs(v);
                ++cur_idx;
            }
        }
        return comp_idx;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> vec = weak_comp(FromMatrixToAdjacencyList(isConnected));
        int mx = 0;
        for (int i : vec)
            mx = max(mx, i);
        return mx + 1;
    }
};