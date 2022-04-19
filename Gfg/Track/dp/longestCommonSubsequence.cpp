// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    string a,b;
    int findAnswer(int i,int j){
        if(i > a.size() || j > b.size()){
            return 0;
        }

        if(a[i] == b[j])
            return 1 + findAnswer(i+1,j+1);
        else
            return max(findAnswer(i,j+1), findAnswer(i+1,j));
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        a = s1;
        b = s2;
        // your code here
        return findAnswer(0,0);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends