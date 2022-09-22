// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool check(int sarr[], int parr[])
    {
        for (int i = 0; i < 26; i++)
            if (sarr[i] < parr[i])
                return false;
        return true;
    }
    void print(int arr[])
    {
        for (int i = 0; i < 26; i++)
            if (arr[i] > 0)
                cout << arr[i] << " ";
        cout << endl;
        for (int i = 0; i < 26; i++)
            if (arr[i] > 0)
                cout << (char)(i + 97) << " ";
        cout << endl<<endl;
    }
    string smallestWindow(string s, string p)
    {
        // Your code here
        string res = "";
        int parr[26] = {0};
        for (int i = 0; i < p.length(); i++)
            parr[(int)p[i] - 97]++;
        print(parr);
        int i = 0, j = -1;
        int sarr[26] = {0} , n = s.length();
        while(i < n && j < n)
        {
            while (check(sarr, parr) == false)
            {
                if (parr[s[i] - 97] > 0)
                    sarr[s[i] - 97]++;
                i++;
                if (i == s.length())
                    break;
            }
            print(sarr);
            while (check(sarr, parr) == true)
            {
                j++;
                if (parr[s[j] - 97] > 0)
                    sarr[s[j] - 97]--;
                if (j >= i - 1)
                    break;
            }
            sarr[s[j] - 97]++;
            print(sarr);
            if (check(sarr, parr))
            {
                if (res == "" || i - j < res.length())
                    res = s.substr(j, i - j);
            }
            sarr[s[j] - 97]--;
        }
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
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} // } Driver Code Ends