#include <bits/stdc++.h>

using namespace std;
vector <int> a[20001];
int ck[20001];
int K, V, E, u, v;
 
void DFS(int x, int c)
{
    ck[x] = c;
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if (ck[y] == 0)
        {
            DFS(y, 3 - c);
        }
    }
}
int main() {
    cin >> K;
    while (K--)
    {
        cin >> V >> E;
        bool ans = true;
        for (int i = 1; i <= 20000; i++)
        {
            a[i].clear();
            ck[i] = 0;
        }
        while (E--)
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= V; i++)
        {
            if (ck[i] == 0)
                DFS(i, 1);
        }
        for (int i = 1; i <= V; i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                int tmp = a[i][j];
                if (ck[i] == ck[tmp])
                    ans = false;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
}

