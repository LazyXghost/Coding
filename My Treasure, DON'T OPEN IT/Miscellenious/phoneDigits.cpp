#include<bits/stdc++.h>
#define pii pair<int, int>
#define fori(s,n) for(int i=s;i<n;i++)
#define forvi(v) for(auto i = v.begin(); i != v.end(); i++)
#define val(x) (*x)
#define ll long long
#define umii unordered_map<int,int>
#define usi unordered_set<int>
#define forvi(v) for(auto i = v.begin(); i != v.end(); i++)
#define takeinputarray(arr,n) fori(0,n){cin>>arr[i];}
#define printarray(arr,n) fori(0,n){cout<<arr[i]<<' ';}cout<<endl;
#define takeinputvector(v,n) fori(0,n){int x;cin>>x;v.push_back(x);}
#define printvector(v) forvi(v){cout<<val(i)<' ';}

using namespace std;

void phoneDigits(int x){
    if (x<= 7)
        cout<<(char)(x* 3 + 91);
    cout<<(char)(x* 3 + 92);
    cout<<(char)(x* 3 + 93);
    if (x>= 7)
        cout<<(char)(x* 3 + 94);
    if (x== 9)
        cout<<(char)(x* 3 + 95);
}