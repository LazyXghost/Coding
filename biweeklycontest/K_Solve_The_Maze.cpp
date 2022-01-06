#include <bits/stdc++.h>
using namespace std;
#define p(a, b) pair<a, b>
#define v(a) vector<a>
#define q(a) queue<a>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define val(x) (*(x))
#define space cout << " ";
#define newline cout << "\n";

struct solution
{
    int n, m;
    v(string) s;
    v(int) dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    q(p(int, int)) que;
    v(v(bool)) vis;
    solution()
    {
        cin >> n >> m;
        s.resize(n);
        loop(i, 0, n - 1) cin >> s[i];
        if (blockableB())
        {
            pushAndChange();
            if (que.size() == 0)
                cout << "Yes\n";
            else if (s[n - 1][m - 1] == '#')
                cout << "No\n";
            else
            {
                vis.resize(n, v(bool)(m, false));
                dfs({n - 1, m - 1});
                bool flag = true;
                while (!que.empty())
                {
                    p(int, int) pos = que.front();
                    que.pop();
                    if (vis[pos.first][pos.second] == false)
                        flag = false;
                }
                if (flag)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
        else
            cout << "No\n";
    }
    void dfs(p(int, int) u)
    {
        int x = u.first, y = u.second;
        vis[x][y] = true;
        loop(pos, 0, 3)
        {
            int tempx = x + dx[pos], tempy = y + dy[pos];
            if (insideGrid(tempx, tempy) && vis[tempx][tempy] == false && s[tempx][tempy]=='.')
                dfs({tempx, tempy});
        }
    }
    void pushAndChange()
    {
        loop(i, 0, n - 1)
            loop(j, 0, m - 1)
                if (s[i][j] == 'G')
                {
                    que.push({i, j});
                    s[i][j] = '.';
                }
                else if (s[i][j] == 'B')
                    s[i][j] = '#';
    }
    bool insideGrid(int a, int b)
    {
        return a >= 0 && a < n && b >= 0 && b < m;
    }
    bool blockableB()
    {
        loop(i, 0, n - 1)
            loop(j, 0, m - 1)
                if (s[i][j] == 'B')
                    loop(pos, 0, 3)
                    {
                        int tempx = i + dx[pos], tempy = j + dy[pos];
                        if (insideGrid(tempx, tempy))
                        {
                            if (s[tempx][tempy] == 'G')
                                return false;
                            else if(s[tempx][tempy] != 'B')
                                s[tempx][tempy] = '#';
                        }
                    }
        return true;
    }
};

int main()
{
    FASTIO;
    tests(t)
    {
        solution sol;
    }
    return 0;
}