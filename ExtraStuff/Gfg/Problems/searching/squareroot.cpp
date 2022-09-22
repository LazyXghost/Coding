#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int x=n;
    while(n*n>x){
        n=n/2;
    }
    while(n*n<x && (n+1)*(n+1) <=x){
        n++;
    }
    cout<<n;
    cout<<endl;
    return 0;
}