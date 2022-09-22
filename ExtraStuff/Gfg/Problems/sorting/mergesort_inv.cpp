#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int mid, int h, int &count)
{
    int ls = mid - l + 1, rs = h - mid;
    int left[ls], right[rs], k = 0;
    for (int i = l; i <= mid; i++)
    {
        left[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = mid + 1; i <= h; i++)
    {
        right[k] = a[i];
        k++;
    }
    int i = 0, j = 0;
    k = l;
    while (i < ls && j < rs)
    {
        while (left[i] <= right[j] && i < ls)
        {
            a[k] = left[i];
            i++;
            k++;
        }
        while (left[i] > right[j] && j < rs)
        {
            a[k] = right[j];
            j++;
            k++;
            count+= ls-i;
        }
    }
    while (i < ls)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < rs)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int h, int &count)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(a, l, mid, count);
        mergesort(a, mid + 1, h, count);
        merge(a, l, mid, h, count);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int count = 0;
    mergesort(a, 0, n - 1, count);
    cout << count << endl;
    return 0;
}