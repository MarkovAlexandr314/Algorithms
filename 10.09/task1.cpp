#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSortWithoutRecursion(const vector<vector<int>> &adj, int n)
{
    vector<int> degree(n);
    vector<int> order;
    queue<int> zero_degree;

    for (auto i : adj)
    {
        for (auto j : i)
        {
            degree[j]++;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        {
            if (degree[i] == 0)
            {
                zero_degree.push(i);
            }
        }
    }

    while (!zero_degree.empty())
    {
        int c = zero_degree.front();
        zero_degree.pop();
        order.push_back(c);
        for (auto i : adj[c])
        {
            degree[i]--;
            if (degree[i] == 0)
            {
                zero_degree.push(i);
            }
        }
    }

    return order;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {}, {1}, {1, 2}};
    for (auto i : topologicalSortWithoutRecursion(adj, 4))
    {
        cout << i << ' ';
    }
}