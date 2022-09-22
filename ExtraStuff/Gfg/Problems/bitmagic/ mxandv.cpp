// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // Function for finding maximum AND value.
    int maxAND(int a[], int n)
    {
        // Your code here
        int mx;
        mx = -1;

        for (int i = 0; i < n; i++)
            if (a[i] > mx)
                mx = a[i];

        int mxbi, x, count, t;
        x = 0;
        count = 0;
        mxbi = log2(mx) + 1;

        for (int bi = mxbi; bi > 0; bi--)
        {
            count = 0;
            t = x + pow(2, bi - 1);
            for (int i = 0; i < n; i++)
            {
                if ((a[i] & t) == t)
                    count++;
                if (count == 2)
                {
                    x = t;
                    break;
                }
            }
        }
        return x;
    }
};

// { Driver Code Starts.

// Driver function
int main()
{
    int t;
    cin >> t; //testcases
    while (t--)
    {
        int n;
        cin >> n; //input n
        int arr[n + 5], i;

        //inserting elements
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        //calling maxAND() function
        cout << obj.maxAND(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends