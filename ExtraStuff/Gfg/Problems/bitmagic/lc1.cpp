// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
public:
    int maxConsecutiveOnes(int n)
    {
        // code here
        int cm = -1;
        int count;
        while (n > 0)
        {
            count = 1;
            while ((n & 1 == 1) && ((n >> 1) & 1 == 1) && n > 0)
            {
                count++;
                n = n >> 1;
            }
            if (count > cm)
            {
                cm = count;
            }
            n = n >> 1;
        }
        return cm;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; //testcases
    while (t--)
    {
        int n;
        cin >> n; //input n
        Solution obj;
        //calling maxConsecutiveOnes() function
        cout << obj.maxConsecutiveOnes(n) << endl;
    }
    return 0;
} // } Driver Code Ends