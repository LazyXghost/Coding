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

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE}) 
// vector<int> v({SIZE OF VECTOR})

long long Number(int a,int b)
{
    unordered_set<int> viewedvalues;
    queue<int> que;
    que.push(a);
    int k = 0;
    bool found = false;
    while(!que.empty()){
        int noofleafes = que.size();
        while(noofleafes--){
            int temp = que.front();
            que.pop();
            if(viewedvalues.find(temp) != viewedvalues.end()){
                continue;
            }
            if (temp == b)
            {
                found = true;
                break;
            }
            else if (temp == 1)
                que.push(temp * 2);
            else if (temp > b){
                que.push(temp-1);
            }
            else {
                que.push(temp*2);
                que.push(temp-1);
            }
            viewedvalues.insert(temp);
        }
        if(found == true){
            break;
        }
        k++;
    }
    return k;
}

int main()
{
    FASTIO;
    int n,m;
    input(n);
    input(m);
    print(Number(n,m));
    return 0;
}