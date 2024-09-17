#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

enum Cloth
{
    jacket = 0,
    watch,
    trousers,
    shirt,
    underpants,
    socks,
    shoes,
    tie,
    belt,
};

vector<int> topological_sort(const vector<vector<int>> &g)
{
    vector<bool> visited(g.size());
    vector<int> order;
    function<void(int)> dfs = [&](int v)
    {
        visited[v] = true;
        for (int u : g[v])
            if (!visited[u])
                dfs(u);
        order.push_back(v);
    };

    for (size_t v = 0; v < g.size(); v++)
    {
        if (!visited[v])
            dfs(v);
    }

    reverse(order.begin(), order.end());
    return order;
}

vector<vector<int>> FromEdgeListToAdjacencyList(const vector<pair<Cloth, Cloth>> &EdgeList, int n)
{
    vector<vector<int>> AdjacencyList(n);
    for (auto i : EdgeList)
    {
        AdjacencyList[i.first].push_back(i.second);
    }
    return AdjacencyList;
}

int main()
{
    vector<pair<Cloth, Cloth>> cloth = {
        {Cloth::tie, Cloth::jacket},
        {Cloth::socks, Cloth::shoes},
        {Cloth::shirt, Cloth::belt},
        {Cloth::shirt, Cloth::tie},
        {Cloth::belt, Cloth::jacket},
        {Cloth::underpants, Cloth::trousers},
        {Cloth::underpants, Cloth::shoes},
        {Cloth::trousers, Cloth::shoes},
        {Cloth::trousers, Cloth::belt},
    };

    int cloth_count = 9;
    vector<int> ans = topological_sort(FromEdgeListToAdjacencyList(cloth, cloth_count));

    for (auto i : ans)
    {
        switch (i)
        {
        case jacket:
            cout << "jacket" << ' ';
            break;
        case watch:
            cout << "watch" << ' ';
            break;
        case trousers:
            cout << "trousers" << ' ';
            break;
        case shirt:
            cout << "shirt" << ' ';
            break;
        case socks:
            cout << "socks" << ' ';
            break;
        case shoes:
            cout << "shoes" << ' ';
            break;
        case Cloth::tie:
            cout << "tie" << ' ';
            break;
        case belt:
            cout << "belt" << ' ';
            break;
        case underpants:
            cout << "underpants" << ' ';
            break;
        }
    }
}