#include <bits/stdc++.h>
using namespace std;

#define um(a, b) unordered_map<a, b>
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define val(x) (*(x))

#define newline cout << "\n";

struct solution
{
    int n, m;
    solution()
    {
        cin >> n >> m;
        um(int, int) distances;
        int currdis = INT_MAX;
        loop(i, 1, n)
        {
            loop(j, 1, m)
            {
                int x = findMaxDistance(i, j);
                currdis = min(currdis, x);
                distances[x]++;
            }
        }
        loop(k, 0, n * m - 1)
        {
            cout << currdis;
            cout << " ";
            distances[currdis]--;
            if (distances[currdis] == 0)
            {
                currdis++;
            }
        }
        newline;
    }
    int findMaxDistance(int a, int b)
    {
        int greater1 = max(abs(a - 1) + abs(b - 1), abs(a - n) + abs(b - 1));
        int greater2 = max(abs(a - 1) + abs(b - m), abs(a - n) + abs(b - m));
        return max(greater1, greater2);
    }
};

int main()
{
    tests(t)
    {
        solution sol;
    }
    return 0;
}