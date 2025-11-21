#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class graph
{
private:
public:
    int vertices;
    vector<vector<int>> adjm;
    graph(int v)
    {
        this->vertices = v;
        this->adjm.resize(v, vector<int>(v, 0));
    }

    int findMinDistVer(vector<int> dv, vector<bool> known)
    {
        int minV = -1;
        int minD = INT_MAX;
        for (int i = 0; i < vertices; i++)
        {
            if (!known[i] && dv[i] < minD)
            {
                minD = dv[i];
                minV = i;
            }
        }
        return minV;
    }

    void dijkstra()
    {
        vector<int> dv(vertices, INT_MAX);
        vector<int> pv(vertices, -1);
        vector<bool> known(vertices, false);
        dv[0] = 0;
        for (int i = 0; i < vertices; i++)
        {
            int u = findMinDistVer(dv, known);
            known[u] = true;
            for (int v = 0; v < vertices; v++)
            {
                if (adjm[u][v] != 0 && !known[v])
                {
                    if (dv[u] + adjm[u][v] < dv[v])
                    {
                        dv[v] = dv[u] + adjm[u][v];
                        pv[v] = u;
                    }
                }
            }
        }
        if (pv[vertices - 1] == -1)
        {
            cout << -1;
            return;
        }
        else
        {
            vector<int> path;
            path.push_back(vertices);
            int curr = vertices - 1;
            while (curr != 0)
            {
                curr = pv[curr];
                path.push_back(curr + 1);
            }
            for (int i = path.size() - 1; i >= 0; i--)
            {
                cout << path[i] << " ";
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    graph *g = new graph(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g->adjm[a - 1][b - 1] = w;
        g->adjm[b - 1][a - 1] = w;
    }

    g->dijkstra();
    return 0;
}