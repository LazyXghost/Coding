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
#define iteratorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define iteratorloopreverse(v, i) for(auto i = v.end()-1;i!=v.begin()-1;i--)
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

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE}) 
// vector<int> v({SIZE OF VECTOR})

int binarysearch(int s[],int start,int end, int key){
    if(s[start]>key)
        return -1;
    else if(start == end)
        return start;
    else if(end == start+1){
        if(s[end]<=key)
            return end;
        return start;
    }

    int mid = (start + end) / 2;
    if (s[mid] == key)
        return mid;
    else if (s[mid] < key)
        start = mid;
    else
        end = mid;
    return binarysearch(s,start,end,key);
}

int noOfBooks(int a[], int n, int t){
    int res = 0;
    int s[n];
    s[0]=a[0];
    forloop(i,1,n-1){
        s[i]=a[i];
        s[i]+=s[i-1];
    }
    forloop(i,0,n-1){
        int first = i;
        int second = binarysearch(s,0,n-1,s[first]+t-a[first]);
        if(second == -1){
            continue;
        }
        res = max(res, second-first+1);
    }
    return res;
}

int main()
{
    FASTIO;
    int n,t;
    input(n);
    input(t);
    int a[n];
    forloop(i,0,n-1){
        input(a[i]);
    }
    print(noOfBooks(a, n, t));
    return 0;
}