#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

string result(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int x = arr[i];
        int upperl = i + 2, lowerl = 2;
        int j = upperl;
        while (j >= lowerl)
        {
            if (x % j != 0)
            {
                break;
            }
            j--;
        }
        if (j == lowerl - 1)
        {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << result(arr, n) << "\n";
    }

    return 0;
}