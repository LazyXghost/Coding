#include <iostream>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include <bits/stdc++.h>
class Solution
{
public:
    //Function to check if the number is sparse or not.
    bool isSparse(int n)
    {
        // Your code
        int newi = -1, previ = -1;
        while (n > 0)
        {
            newi = log2(n - (n & (n - 1))) + 1;
            n = n & (n - 1);
            cout<<n<<" "<<previ<<" "<<newi<<endl;
            if (newi == previ + 1)
                return false;
            previ = newi;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t, n;

    //testcases
    cin >> t;
    while (t--)
    {
        //initializing n
        cin >> n;

        //printing 1 if isSparse() returns true
        //else 0
        Solution ob;
        if (ob.isSparse(n))
        {
            cout << "1" << endl;
        }
        else
            cout << "0" << endl;
    }
    return 0;
}
// } Driver Code Ends