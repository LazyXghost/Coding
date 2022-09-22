// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int csb(int x)
    {
        if (x == 0)
            return 0;
        return csb(x / 2) + (x & 1);
    }
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int first = 1, second = 1;
        int i = 1;
        int count = 0;
        while (first != 0 || second != 0)
        {
            int p1 = pow(2, i);
            int p2 = pow(2, i - 1);
            int x = (n + 1) / p1;
            first = x * p2;
            second = (n + 1) % p1;
            if (second >= p2)
            {
                second = second - p2;
            }
            else
                second = 0;

            count += (first + second);
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) //while testcases exist
    {
        int n;
        cin >> n; //input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}
// } Driver Code Ends