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
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define loopreverse(i, a, b) for (int i = a; i >= b; i--)
#define iteratorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define iteratorloopreverse(v, i) for(auto i = v.end()-1;i!=v.begin()-1;i--)
#define printArray(arr, n, i) for(int i = 0;i<n;i++){print(arr[i]);space;}newline;
#define inputArray(arr, n, i) for(int i = 0;i<n;i++){input(arr[i])}
#define printVector(v, i) for(auto i = v.begin();i!=v.end();i++){print(val(i));space;}newline;
#define inputVector(v, n, i) for(int i = 0;i<n;i++){int x;input(x);v.push_back(x);}
#define val(x) (*(x))

#define print(x) cout<<x
#define input(x) cin>>x
#define space cout<<" "
#define newline cout<< "\n"

const ll MOD = 1e9 + 7;

bool comparator(pii a, pii b){
    return (a.first < b.first);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE}) 
// vector<int> v({SIZE OF VECTOR})

void permutation(int n,int a,int b){
    int maxpossible;
    if(n%2 == 1){
        maxpossible = n/2;
    }
    else{
        maxpossible = n/2 - 1;
    }

    if(a > maxpossible || b>maxpossible || a+b>n-2 || abs(b-a)>1){
        print(-1);
        newline;
    }
    else
    {
        int arr[n];
        if (a == b)
        {
            loop(i,0,n-1){
                arr[i] = i+1;
            }
        }
        else{
            if(b>a){
                arr[0] = n;
                loop(i,1,n-1){
                    arr[i] = i;
                }
            }
            else{
                arr[n-1] = 1;
                loop(i,0,n-2){
                    arr[i] = i+2;
                }
                a--;
            }
        }
        int i = 1;
        if(b>a){
            i=2;
        }
        while (a--)
        {
            swap(arr[i], arr[i + 1]);
            i += 2;
        }
        loop(i,0,n-1){
            print(arr[i]);
            space;
        }
        newline;
    }
}

int main()
{
    FASTIO;
    tests(t){
        int n,a,b;
        input(n);
        input(a);
        input(b);
        permutation(n,a,b);
    }
    return 0;
}