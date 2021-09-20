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

// 0 for rest
// 1 for contest
// 2 for gym
// 3 for both
int minDays(vi &v, unordered_map<int,unordered_map<int,int>> &states, int i=0, int lastchoice=0){
    if(i >= v.size()){
        return 0;
    }
    else if(states.find(i)!=states.end() && states[i].find(lastchoice)!=states[i].end()){
        return states[i][lastchoice];
    }

    int res, rested, contested, gymmed;
    rested = 1 + minDays(v, states, i + 1, 0);
    
    if((v[i] == 0) || (v[i]==1 && lastchoice ==1) || (v[i]==2 && lastchoice ==2)){
        res = rested;
    }
    else if ((v[i] == 1) || (v[i] == 3 && lastchoice == 2)){
        contested = minDays(v, states, i + 1, 1);
        res = min(rested, contested);
    }
    else if ((v[i] == 2) || (v[i] == 3 && lastchoice == 1)){
        gymmed = minDays(v, states, i + 1, 2);
        res = min(rested, gymmed);
    }
    else{
        contested = minDays(v, states, i + 1, 1);
        gymmed = minDays(v, states, i + 1, 2);
        res = min(rested, min(contested, gymmed));
    }

    // DYNAMIC PROGRAMMIN PART
    if (states.find(i) != states.end())
        states[i][lastchoice] = res;
    else
    {
        unordered_map<int, int> temp;
        temp[lastchoice] = res;
        states[i] = temp;
    }
    return res;
}

int main()
{
    FASTIO;
    int n;
    input(n);
    vi a;
    unordered_map<int,unordered_map<int,int>> states;
    inputVector(a,n,i);
    print(minDays(a, states));
    return 0;
}