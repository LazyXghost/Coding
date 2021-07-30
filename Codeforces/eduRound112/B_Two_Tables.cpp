#include <bits/stdc++.h>
#define pii pair<int, int>
#define fori(s, n) for (int i = s; i < n; i++)
#define forvi(v) for (auto i = v.begin(); i != v.end(); i++)
#define val(x) (*x)
#define ll long long
#define umii unordered_map<int, int>
#define usi unordered_set<int>
#define forvi(v) for (auto i = v.begin(); i != v.end(); i++)
#define takeinputarray(arr, n) \
    fori(0, n) { cin >> arr[i]; }
#define printarray(arr, n)                \
    fori(0, n) { cout << arr[i] << ' '; } \
    cout << endl;
#define takeinputvector(v, n) \
    fori(0, n)                \
    {                         \
        int x;                \
        cin >> x;             \
        v.push_back(x);       \
    }
#define printvector(v) \
    forvi(v) { cout << val(i) < ' '; }

using namespace std;

int minDis(pii room, pii pt1, pii pt2, pii t2)
{
    int space1 = pt1.first, space2 = room.second - pt2.second, space3 = room.first - pt2.first, space4 = pt1.second;
    int lmov = -1, rmov = -1, tmov = -1, bmov = -1;
    int xmov = -1, ymov = -1;
    if (space1 + space3 >= t2.first && space2 + space4 >= t2.second)
    {
        if (t2.first > space1)
            lmov = t2.first - space1;
        else
            lmov = 0;
        if (t2.first > space3)
            rmov = t2.first - space3;
        else
            rmov = 0;
        xmov = min(lmov, rmov);

        if (t2.second > space2)
            tmov = t2.second - space2;
        else
            tmov = 0;
        if (t2.second > space4)
            bmov = t2.second - space4;
        else
            bmov = 0;
        ymov = min(tmov, bmov);
    }
    else if (space1 + space3 >= t2.first)
    {

        if (t2.first > space1)
            lmov = t2.first - space1;
        else
            lmov = 0;
        if (t2.first > space3)
            rmov = t2.first - space3;
        else
            rmov = 0;
        xmov = min(lmov, rmov);
    }
    else if (space2 + space4 >= t2.second)
    {
        if (t2.second > space2)
            tmov = t2.second - space2;
        else
            tmov = 0;
        if (t2.second > space4)
            bmov = t2.second - space4;
        else
            bmov = 0;
        ymov = min(tmov, bmov);
    }
    if (xmov != -1 && ymov != -1)
        return min(xmov, ymov);
    return max(xmov, ymov);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        pii room, pt1, pt2, t2;
        cin >> room.first >> room.second;
        cin >> pt1.first >> pt1.second;
        cin >> pt2.first >> pt2.second;
        cin >> t2.first >> t2.second;
        int x = minDis(room, pt1, pt2, t2);
        if (x == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << fixed << setprecision(9) << (double)x << endl;
        }
    }

    cout << endl;
    return 0;
}
