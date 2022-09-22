// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
#define pii pair<int, int>
    //Function to find the kth smallest element in the array.
    pii min_max(int a[], int n)
    {
        int min = a[0], max = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] > max)
                max = a[i];
            if (a[i] < min)
                min = a[i];
        }
        return pii(min, max);
    }
    int cf(int a[], int x, int n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= x)
            {
                count++;
            }
        }
        return count;
    }
    int kthSmallest(int arr[], int n, int k)
    {
        // Your code here
        pii mn_mx = min_max(arr, n);
        int mid = (mn_mx.first + mn_mx.second) / 2;
        int count = -1;
        while (count != k)
        {
            count = cf(arr, mid, n);
            if (count < k)
                mid = (mid + mn_mx.second) / 2;
            else if (count > k)
                mid = (mn_mx.first + mid) / 2;
            else if (count == k)
                return mid;
        }
        return mid;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.kthSmallest(arr, n, k) << endl;
    }
    return 0;
} // } Driver Code Ends