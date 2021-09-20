#include<bits/stdc++.h>
using namespace std;

#define vect vector<int>

int main()
{
    int n;
    cin>>n;
    double a,b,c,d;
    double x,y;
    cin>>a>>b>>c>>d;
    x=(a+c)/2;y=(b+d)/2;
    double r=(pow(pow(c-a,2) + pow(d-b,2),0.5))/2;
    double angle=((2*M_PI)/n);
    double angle2=atan((b-y)/(a-x));
    if(a<x)
    angle2=M_PI+angle2;
    angle=angle+angle2;
    cout<<fixed<<setprecision(11)<<x+r*cos(angle)<<" "<<fixed<<setprecision(11)<<y+r*sin(angle);
    cout<<endl;
    return 0;
}