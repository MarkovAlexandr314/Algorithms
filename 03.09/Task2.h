#ifndef TASK2_H
#define TASK2_H

#include <vector>

using namespace std;

class Solution
{
    enum Color
    {
        WHITE,
        GRAY,
        BLACK
    };

    bool dfs(vector<vector<int>> AdjList, vector<Color> color, int n, int v = -1)
    {
        color[n] = GRAY;

        for (int i : AdjList[n])
        {
            if (i != v)
            {
                if (color[i] == GRAY)
                {
                    return true;
                }
                if ((color[i] == WHITE) && (dfs(AdjList, color, i, i)))
                {
                    return true;
                }
            }
        }

        color[n] = BLACK;

        return false;
    }

public:
    bool isCycle(vector<vector<int>> AdjacencyList, int n)
    {
        vector<Color> color(n);
        for (auto i : color)
        {
            i = WHITE;
        }

        for (size_t i = 0; i < n; i++)
        {
            if (color[i] == WHITE)
                if (dfs(AdjacencyList, color, i))
                    return true;
        }

        return false;
    }
};

#endif /* TASK2_H */