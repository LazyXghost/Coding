#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> arr;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        int element = arr[n - 1];
        int elementcount = 1;

        int res = 0;

        int i = n - 2;
        while (i >= 0)
        {
            if (arr[i] != element)
            {
                i -= elementcount;
                elementcount *= 2;
                res++;
            }
            else
            {
                elementcount++;
                i--;
            }
        }

        cout << res << endl;
    }
    return 0;
}