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
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> g(n);
        for (int i{0}; i < n; ++i)
        {
            if (manager[i] != -1)
                g[manager[i]].push_back(i);
        }

        vector<int> minutes(g.size());
        vector<string> color(g.size(), "WHITE");
        vector<int> parent(g.size());
        int maxtime = 0;

        function<void(int, int)> dfs = [&](int v, int p = -1)
        {
            parent[v] = p;
            color[v] = "GRAY";
            if (p == -1)
            {
                minutes[v] = informTime[headID];
            }
            else
            {
                minutes[v] = minutes[p] + informTime[p];
            }
            maxtime = max(maxtime, minutes[v]);

            for (int to : g[v])
            {
                if (color[to] != "WHITE")
                    continue;
                dfs(to, v);
            }

            color[v] = "BLACK";
        };

        for (int i : g[headID])
        {
            dfs(i, -1);
        }
        return maxtime;
    }
};