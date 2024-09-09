#ifndef TASK4_H
#define TASK4_H

#include <vector>

using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<vector<int>> persons(n, vector<int>(2));
        for (auto i : trust)
        {
            persons[i[0] - 1][1] += 1;
            persons[i[1] - 1][0] += 1;
        }
        for (int i{0}; i < persons.size(); ++i)
        {
            if ((persons[i][0] == n - 1) && (persons[i][1] == 0))
                return i + 1;
        }
        return -1;
    }
};

#endif /* TASK4_H */