// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int a[], int n)
    {
        sort(a, a + n);
        int count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (a[i] + a[i + 1] > a[n - 1])
            {
                int no = n - i;
                count += no * (no - 1) * (no - 2) / 6;
                return count;
            }
            int k = n - 1, j = i + 1;
            while (j < k)
            {
                if (a[i] + a[j] > a[k])
                {
                    count += k - j;
                    k--;
                    j = i + 1;
                }
                else
                {
                    j++;
                    if (j == k)
                    {
                        k--;
                        j = i + 1;
                    }
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findNumberOfTriangles(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends