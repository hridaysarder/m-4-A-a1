#include <iostream>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int x1, y1, x2, y2;
bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != '#' && vis[x][y] == false)
        return true;
    else
        return false;
}

bool dfs(int si, int sj)
{
    if (si == x2 && sj == y2)
        return true;

    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i];
        int cj = sj + dy[i];

        if (valid(ci, cj))
        {
            if (dfs(ci, cj))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                x1 = i;
                y1 = j;
            }
            else if (graph[i][j] == 'B')
            {
                x2 = i;
                y2 = j;
            }
        }
    }
    if (dfs(x1, y1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
