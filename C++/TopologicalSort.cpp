#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes)
{
    vector<int> inDegree(nodes, 0);
    for (int i = 0; i < edges; i++)
    {
        int dest = graph[i][1];
        inDegree[dest]++;
    }
    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (int i = 0; i < edges; i++)
        {
            if (graph[i][0] == front)
            {
                // an edge starting from this node
                int dest = graph[i][1];
                inDegree[dest]--;
                // deleting the edge -> decreasing the inDegree
                if (inDegree[dest] == 0)
                {
                    q.push(dest);
                }
            }
        }
    }

    return ans;
}

struct node
{
    int edges, nodes;
    vector<vector<int>> graph;
};
class Runner
{
    int t;
    vector<node> g;

public:
    void takeInput()
    {
        cin >> t;
        g.resize(t);
        for (int i = 0; i < t; i++)
        {
            int edges, nodes;
            cin >> nodes >> edges;
            g[i].edges = edges;
            g[i].nodes = nodes;
            g[i].graph.resize(edges);
            for (int j = 0; j < edges; j++)
            {
                int f, s;
                cin >> f >> s;
                g[i].graph[j].push_back(f);
                g[i].graph[j].push_back(s);
            }
        }
    }
    bool check(vector<vector<int>> &graph, int edges, int nodes, vector<int> ans)
    {
        vector<int> depth(nodes + 1, 0);
        int cnt = 0;
        for (int i : ans)
        {
            if (i < 0 || i >= nodes)
                return false;
            depth[i] = ++cnt;
        }

        for (int i = 0; i < nodes; i++)
        {
            if (!depth[i])
                return false;
            for (int next : graph[i])
                if (depth[next] <= depth[i])
                {
                    return false;
                }
        }
        return true;
    }

    vector<node> getCopy()
    {
        vector<node> arrCopy;
        arrCopy = g;
        return arrCopy;
    }

    void execute()
    {
        vector<node> arrCopy = getCopy();
        for (int i = 0; i < arrCopy.size(); i++)
        {
            vector<int> x = topologicalSort(arrCopy[i].graph, arrCopy[i].edges, arrCopy[i].nodes);
        }
    }

    void executeAndPrintOutput()
    {
        vector<node> arrCopy = getCopy();
        vector<vector<int>> g;
        for (int i = 0; i < arrCopy.size(); i++)
        {
            vector<int> x = topologicalSort(arrCopy[i].graph, arrCopy[i].edges, arrCopy[i].nodes);
            g.resize(arrCopy[i].nodes + 1);
            for (vector<int> edge : arrCopy[i].graph)
                g[edge[0]].push_back(edge[1]);

            if (check(g, arrCopy[i].edges, arrCopy[i].nodes, x))
                cout << "Correct" << endl;
            else
                cout << "NO" << endl;

            g.clear();
        }
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}