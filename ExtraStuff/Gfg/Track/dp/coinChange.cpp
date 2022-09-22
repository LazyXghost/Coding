// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    vector<vector<long long>> dp;
    vector<int> coins;
    int size;
  public:
    long long int findAnswer(int value, int ind){
        // cout<<"For value = "<<value<<" ind = "<<ind;
        // cout<<endl;

        if(value == 0)
            return 1;
        else if(value<0 || (value > 0 && ind>=size))
            return 0;

        if(dp[value][ind]!=-1){
            // cout<<"For ["<<value<<"]["<<ind<<"]";
            // cout<<endl;
            return dp[value][ind];
        }

        long long res = 0;
        for(int i = value/coins[ind];i>=0;i--)
            res += findAnswer(value - i*coins[ind], ind + 1);

        // return dp[value][ind] = res;
        return res;
    }

    long long int count(int S[], int m, int n) {
        size = m;
        for(int i = 0;i<m;i++){
            coins.push_back(S[i]);
        }
        // dp.resize(n+1, vector<long long>(m, -1));
        return findAnswer(n,0);
        // code here.
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends