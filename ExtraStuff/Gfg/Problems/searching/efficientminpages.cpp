#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int sumarray(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}
int maxarray(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int minpages(int a[], int n, int l, int r, int k)
{
    int mid = (l + r) / 2, sum = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > mid && r - l != 1)
        {
            sum = a[i];
            count++;
        }
        else if (r - l == 1)
        {
            if (sum > mid && sum>r)
            {
                sum = a[i];
                count++;
            }
            else if (sum == mid)
            {
                return mid;
            }
            else if (sum == r)
            {
                return r;
            }
        }
        // cout << l << " " << mid << " " << r << " " << sum << endl;
    }
    if (count <= k)
        r = mid;
    else
        l = mid;
    return minpages(a, n, l, r, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], s[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = maxarray(a, n);
    int sm = sumarray(a, n);
    int k;
    cin >> k;
    int res = minpages(a, n, mx, sm, k);
    cout << res << endl;
    return 0;
}