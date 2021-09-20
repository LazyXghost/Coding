#include<bits/stdc++.h>
using namespace std;

// typedef is used to give datatype a newname
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

// define is used to give things an alias
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fill(start, end, val) fill(start, end, val)

#define tests(t) int t; cin >> t; while(t--)
#define forloop(i, a, b) for (int i = a; i <= b; i++)
#define forloopreverse(i, a, b) for (int i = a; i >= b; i--)
#define vectorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define vectorloopreverse(v, i) for(auto i = v.end()-1;i!=v.begin()-1;i--)
#define printArray(arr, n, i) for(int i = 0;i<n;i++){print(arr[i]);space;}newline;
#define inputArray(arr, n, i) for(int i = 0;i<n;i++){input(arr[i])}
#define printVector(v, i) for(auto i = v.begin();i!=v.end();i++){print(val(i));space;}newline;
#define inputVector(v, n, i) for(int i = 0;i<n;i++){int x;input(x);v.push_back(x);}
#define val(x) (*(x))

#define print(x) cout<<x;
#define input(x) cin>>x;
#define space cout<<" ";
#define newline cout<< "\n";

const ll MOD = 1e9 + 7;

void maxBeautyDifference(int b[],int n){
    int mn = b[0],mx = b[0];
    forloop(i,1,n-1){
        mn = min(mn, b[i]);
        mx = max(mx, b[i]);
    }
    long long mncount = 0,mxcount = 0;
    forloop(i,0,n-1){
        if(b[i] == mn){
            mncount++;
        }
        else if(b[i] == mx){
            mxcount++;
        }
    }
    long long ways = mncount * mxcount;
    if(mn == mx){
        ways = mncount * (mncount-1)/2;
    }
    print(mx - mn);
    space;
    print(ways);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE}) 
// vector<int> v({SIZE OF VECTOR})

int main()
{
    FASTIO;
    int n;
    input(n);
    int b[n];
    forloop(i,0,n-1){
        input(b[i]);
    }
    maxBeautyDifference(b,n);
    return 0;
}