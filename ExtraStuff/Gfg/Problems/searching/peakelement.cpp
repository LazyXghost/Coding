#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

int naivepeakelement(int a[],int n){
    if(a[0]>a[1])
    return 0;
    if(a[n-1]>a[n-2])
    return n-1;
    for(int i=1;i<n-1;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            return i;
        }
    }
    return -1;
}
int betterpeakelement(int a[],int l,int r,int n){
    if(a[0]>a[1])
    return 0;
    if(a[n-1]>a[n-2])
    return n-1;
    int mid = (l+r)/2;
    if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
    return mid;
    else
    if(a[mid]>a[mid-1])
    l=mid+1;
    else  
    r=mid-1;
    return betterpeakelement(a,l,r,n);
}//works only when array dont have any two values equal

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
    int indn= naivepeakelement(a,n);
    cout<<a[indn]<<" ";
    int indb= betterpeakelement(a,0, n-1,n);
    cout<<a[indb]<<endl;
    return 0;
}