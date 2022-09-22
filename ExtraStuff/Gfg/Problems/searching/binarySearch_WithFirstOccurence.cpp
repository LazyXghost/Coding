#include <bits/stdc++.h>
#define vi vector<int>

int binarySearch(int a[], int l, int r, int x)
{
    if (l == r and a[l] != x)
        return -1;
    if (l == r and a[l] == x)
        return l;
    int mid = (l + r) / 2;
    if (a[mid] > x)
        return binarySearch(a, l, mid - 1, x);
    else if (a[mid] < x)
        return binarySearch(a, mid + 1, r, x);
    else
        return mid;
}
int firstOccurence(int a[], int si, int x)
{
    while (a[si] == x){
        si--;
    }
    si++;
    return si;
}

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, si;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    si = binarySearch(a, 0, n - 1, x);
    cout << si<<endl;
    cout << firstOccurence(a, si, x);
    cout << endl;
    return 0;
}