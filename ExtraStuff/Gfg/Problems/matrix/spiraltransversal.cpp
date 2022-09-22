// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> a, int r, int c)
    {
        // code here
        vector<int> v;
        int istart = 0, jstart = 0, iend = r - 1, jend = c - 1;
        int i, j;
        while (v.size()!=r*c)
        {
            i = istart;
            j = jstart;

            istart++;

            while (v.size()!=r*c)
            {
                v.push_back(a[i][j]);
                if (j == jend)
                    break;
                j++;
            }
            jend--;
            i++;
            
            while (v.size()!=r*c)
            {
                v.push_back(a[i][j]);
                if (i == iend)
                    break;
                i++;
            }
            iend--;
            j--;
            
            while (v.size()!=r*c)
            {
                v.push_back(a[i][j]);
                if (j == jstart)
                    break;
                j--;
            }
            jstart++;
            i--;
            
            while (v.size()!=r*c)
            {
                v.push_back(a[i][j]);
                if (i == istart)
                    break;
                i--;
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends