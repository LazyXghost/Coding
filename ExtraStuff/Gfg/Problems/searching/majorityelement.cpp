#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>

using namespace std;

int majelem(int a[], int n)
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[res])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[res])
        {
            count++;
        }
    }
    if (count > n / 2)
        return res;
    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = majelem(a, n);
    if (x != -1)
        cout << a[x] << endl;
    else
        cout << x << endl;
    return 0;
}
// time complexity is O(n) in this