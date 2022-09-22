#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int searchsr(int a[], int l, int r, int x)
{
    if (l == r and a[l] != x)
        return -1;
    if (l == r and a[l] == x)
        return l;

    int mid = (l + r) / 2;
    if (a[mid] == x)
        return mid;

    if (a[mid] < a[l]) //right half sorted
        if (a[mid] < x && a[r] >= x)
            l = mid + 1;
        else
            r = mid - 1;
    else //left half sorted
        if (a[mid] > x && a[l] <= x)
        r = mid - 1;
    else
        l = mid + 1;
    return searchsr(a, l, r, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t = 7;
    while (t--)
    {
        int x;
        cin >> x;
        int search = searchsr(a, 0, n - 1, x);
        cout << search << " ";
    }
    return 0;
}