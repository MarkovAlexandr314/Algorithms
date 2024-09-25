#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
#include <set>
#include <deque>
#include "unordered_set"
#include "utility"

using namespace std;

class Solution
{
    enum Color
    {
        WHITE,
        GRAY,
        BLACK
    };

    vector<vector<int>> bridges(const vector<vector<int>> &g)
    {
        // всегда неорграф
        vector<Color> color(g.size());
        vector<vector<int>> bs;
        vector<int> tup(g.size()), tin(g.size());
        int t = 0; // time
        /* pv == parent of v*/
        function<void(int, int)> dfs = [&](int v, int pv)
        {
            color[v] = GRAY;
            tin[v] = t++;
            tup[v] = tin[v];
            for (int u : g[v])
            {
                if (u == pv) // не берем родителя
                    continue;
                else if (color[u] == GRAY)
                    tup[v] = min(tup[v], tin[u]);
                else if (color[u] == WHITE)
                {
                    dfs(u, v);
                    tup[v] = min(tup[v], tup[u]);
                    if (tin[v] < tup[u]) // нашли мост, заносим его
                    {
                        bs.push_back({v, u});
                    }
                }
            }
            color[v] = BLACK;
        };
        for (size_t v = 0; v < g.size(); v++)
        {
            if (color[v] == WHITE)
                dfs(v, -1);
        }
        return bs;
    }

    vector<vector<int>> FromEdgeListToAdjacencyList(vector<vector<int>> EdgeList, int n)
    {
        vector<vector<int>> AdjacencyList(n);
        for (auto i : EdgeList)
        {
            AdjacencyList[i[0]].push_back(i[1]);
            AdjacencyList[i[1]].push_back(i[0]);
        }
        return AdjacencyList;
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        return bridges(FromEdgeListToAdjacencyList(connections, n));
    }
};