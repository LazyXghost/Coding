// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        int cs[26]={0};
        string x;
        for(int i = 0;i<arr.length();i++)
            cs[(int)arr[i] - 97]+=1;
        for(int i=0;i<26;i++){
            while(cs[i]!=0){
                x+=char(i+97);
                cs[i]--;
            }
        }
        return x;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends