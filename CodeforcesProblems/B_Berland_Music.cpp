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

#define print(x) cout<<x;
#define input(x) cin>>x;
#define space cout<<" ";
#define newline cout<< "\n";

const ll MOD = 1e9 + 7;

bool comparator(pii a, pii b){
    return (a.first < b.first);
}

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE}) 
// vector<int> v({SIZE OF VECTOR})

void findanswer(int p[], int n, string s){
    int count = 0;
    loop(i,0,n-1){
        if(s[i]=='0'){
            count++;
        }
    }
    unordered_set<int> zero, one;
    loop(i,0,count-1){
        zero.insert(i+1);
    }
    loop(i,count+1,n){
        one.insert(i);
    }
    unordered_map<int,char> faults;
    
    loop(i,0,n-1){
        if((s[i]=='0' && p[i]<=count) || (s[i]=='1' && p[i]>count)){
            if(s[i]=='0'){
                zero.erase(zero.find(p[i]));
            }
            else{
                one.erase(one.find(p[i]));
            }
        }
        else{
            faults.insert({i,s[i]});
        }
    }

    iteratorloop(faults,i){
        pair<int,char> fault = val(i);
        if(fault.second == '0'){
            p[fault.first] = val(zero.begin());
            zero.erase(zero.begin());
        }
        else{
            p[fault.first] = val(one.begin());
            one.erase(one.begin());
        }
    }
    printArray(p,n,i);
}

int main()
{
    // FASTIO;
    tests(t){
        int n;
        input(n);
        int p[n];
        inputArray(p,n,i);
        string s;
        input(s);
        findanswer(p,n, s);
    }
    return 0;
}