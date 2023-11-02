#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool containsCycle(vector<vector<int>> &edges, int nodes, int start, vector<bool> &isVisited, vector<bool> &inPath, int e)
{
    isVisited[start] = true;
    inPath[start] = true;
    for (int i = 0; i < e; i++)
    {
        int source = edges[i][0];
        int dest = edges[i][1];
        if (source == start)
        {
            if (inPath[dest])
            {
                return true;
            }
            bool a = containsCycle(edges, nodes, dest, isVisited, inPath, e);
            if (a)
            {
                return true;
            }
        }
    }
    inPath[start] = false;
    return false;
}

bool isCyclic(vector<vector<int>> &edges, int nodes, int e)
{
    vector<bool> isVisited(nodes, false);
    vector<bool> inPath(nodes, false);

    for (int i = 0; i < nodes; i++)
    {
        if (!isVisited[i])
        {
            bool a = containsCycle(edges, nodes, i, isVisited, inPath, e);
            if (a)
            {
                return true;
            }
        }
    }
    return false;
}

class Runner
{
    int t;

    vector<int> v;

    vector<int> e;

    vector<vector<vector<int>>> edges;

public:
    void takeInput()
    {

        cin >> t;

        v.resize(t);
        e.resize(t);
        edges.resize(t);

        for (int c = 0; c < t; c++)
        {
            int n, m;
            cin >> n >> m;
            v[c] = n;
            e[c] = m;
            edges[c].resize(m);
            for (int i = 0; i < m; i++)
            {
                edges[c][i].resize(2);
                cin >> edges[c][i][0] >> edges[c][i][1];
            }
        }
    }

    void execute()
    {

        vector<int> vCopy = v;
        vector<int> eCopy = e;
        vector<vector<vector<int>>> edgesCopy = edges;

        for (int i = 0; i < t; i++)
        {
            bool ans = isCyclic(edgesCopy[i], vCopy[i], eCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {

        for (int i = 0; i < t; i++)
        {

            bool ans = isCyclic(edges[i], v[i], e[i]);

            if (ans == true)
            {
                cout << "true";
            }
            else
            {
                cout << "false";
            }

            cout << "\n";
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
