#include<bits/stdc++.h>
using namespace std;

bool comparator(int a, int b)
{
    return (a < b);
}
// it sorts in increasing order of elements

int main(){
    vector<int> v;
    sort(v.begin(),v.end(), comparator);
}