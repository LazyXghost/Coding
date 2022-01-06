#include<bits/stdc++.h>
using namespace std;

// typedef gives datatype a newname
typedef long long ll;
typedef long double ld;
#define p(a,b) pair<a,b>
#define v(a) vector<a>
#define q(a) queue<a>
#define st(a) stack<a>
#define s(a) set<a>
#define ms(a) multiset<a>
#define us(a) unordered_set<a>
#define m(a,b) map<a,b>
#define mm(a,b) multimap<a,b>
#define um(a,b) unordered_map<a,b>

// define gives things an alias
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fill(start, end, val) fill(start, end, val)

#define tests(t) int t; cin >> t; while(t--)
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define iteratorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define inputArray(arr, n, i) for(int i = 0;i<n;i++){cin>>arr[i]}
#define inputVector(v, n, i) for(int i = 0;i<n;i++){int x;cin>>x;v.push_back(x);}
#define val(x) (*(x))

#define printArray(arr, n, i) for(int i = 0;i<n;i++){cout<<arr[i];space;}newline;
#define printVector(v, i) for(auto i = v.begin();i!=v.end();i++){cout<<val(i);space;}newline;
#define space cout<<" ";
#define newline cout<< "\n";

const ll MOD = 1e9 + 7;

bool comparator(p(int,int) a, p(int,int) b){
    return (a.first < b.first);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE}) 
// vector<int> v({SIZE OF VECTOR})

struct solution{
    string s;
    solution(){
        cin>>s;
        int arr[26]={0};
        loop(i, 0, s.length()-1){
            arr[(int)s[i] - 97]++;
        }
        string res = "";
        loop(i,0,25){
            char c = i+97;
            while(arr[i]!=0){
                res+=c;
                arr[i]--;
            }
        }
        cout<<res;
        newline;
    }
};

int main()
{
    FASTIO;
    tests(t){
    solution sol;
    }
    return 0;
}