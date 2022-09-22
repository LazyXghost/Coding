// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum)
    {
        //Your code here
        // 10 2  -2 -20 10
        // 10 12 10 -10  0
        for (int i = 1; i < n; i++)
        {
            arr[i] = arr[i] + arr[i - 1];
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        cout<<endl;
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == sum)
                count++;
            if (m.find(arr[i] - sum) != m.end())
                count += (*m.find(arr[i] - sum)).second;
            m[arr[i]]++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> sum;
        Solution obj;
        cout << obj.subArraySum(arr, n, sum) << endl;
    }
    return 0;
} // } Driver Code Ends