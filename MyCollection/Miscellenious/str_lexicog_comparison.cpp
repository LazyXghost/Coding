#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    string a,b;
    //if string a is lexicographically smaller than b then a<b
    a = "aa";
    b = "ab";
    if(a<b){
        cout<<a;
    }
    else
    cout<<b;
    cout<<endl;
    return 0;
}