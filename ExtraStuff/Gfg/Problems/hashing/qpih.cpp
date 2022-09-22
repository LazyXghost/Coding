// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    //Function to fill the array elements into a hash table
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector<int> &hash, int hashSize, int arr[], int sizeOfArray)
    {
        //Your code here
        fill(hash.begin(),hash.end(),-1);
        int probe, count = 0;
        for (int i = 0; i < sizeOfArray; i++)
        {
            if (count == hashSize)
                break;
            probe = arr[i] % hashSize;
            int j = 1;
            while (hash[probe] != -1)
            {
                probe = (probe + (j * j)) % hashSize;
                j++;
            }
            hash[probe] = arr[i];
            count++;
            // for (int i = 0; i < hashSize; i++)
            //     cout << hash[i] << " ";

            // cout << endl;
        }
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

        int N;
        cin >> N;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        vector<int> hash(hashSize);
        Solution obj;
        obj.QuadraticProbing(hash, hashSize, arr, N);

        for (int i = 0; i < hashSize; i++)
            cout << hash[i] << " ";

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends