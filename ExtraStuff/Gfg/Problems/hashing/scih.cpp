// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Complete this function
    //Function to insert elements of array in the hashTable avoiding collisions.
    vector<vector<int>> separateChaining(int hS, int a[], int n)
    {
        //Your code here
        vector<vector<int>> res;
        vector<int> v[hS];
        for (int i = 0; i < n; i++)
            v[a[i] % hS].push_back(a[i]);
        for (int i = 0; i < hS; i++)
            res.push_back(v[i]);
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
        int hashSize;
        cin >> hashSize;

        int sizeOfArray;
        cin >> sizeOfArray;
        int arr[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++)
            cin >> arr[i];
        Solution obj;
        vector<vector<int>> hashTable;
        hashTable = obj.separateChaining(hashSize, arr, sizeOfArray);

        for (int i = 0; i < hashTable.size(); i++)
        {
            if (hashTable[i].size() > 0)
            {
                cout << i << "->";
                for (int j = 0; j < hashTable[i].size() - 1; j++)
                {
                    cout << hashTable[i][j] << "->";
                }
                cout << hashTable[i][hashTable[i].size() - 1];
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
};
// } Driver Code Ends