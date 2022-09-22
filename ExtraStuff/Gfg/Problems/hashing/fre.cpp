// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    //Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n)
    {
        //code here
        unordered_map<int, int> m;
        int res = n;
        for (int i = 0; i < n; i++)
            if (m.find(arr[i]) != m.end())
                res = min(res, (*m.find(arr[i])).second);
            else
                m[arr[i]] = i + 1;
        if (res == n)
            return -1;
        else
            return res;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
// } Driver Code Ends