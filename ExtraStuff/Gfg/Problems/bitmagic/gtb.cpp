// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {

        // Your code here
        int x = n;
        int msb = 0;
        while (x > 0)
        {
            x = x>>1;
            msb++;
        }
        for (int i = msb - 2; i >= 0; i--)
        {
            if (((n >> (i + 1)) & 1) == 1)
                if ((n >> i) & 1 == 1)
                    n -= pow(2, i);
                else
                    n += pow(2, i);
        }
        return n;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t, n;
    cin >> t; //testcases
    while (t--)
    {
        cin >> n; //initializing n

        Solution ob;
        //calling function grayToBinary()
        cout << ob.grayToBinary(n) << endl;
    }
}
// } Driver Code Ends