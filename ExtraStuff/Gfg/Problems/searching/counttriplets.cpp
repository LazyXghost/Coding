#include <bits/stdc++.h>
#define pii pair<int, int>
#define pipii pair<int, pair<int, int>>
#define vpipii vector<pipii>
#define vpii vector<pii>

using namespace std;

pipii vpb(int l, int mid, int h)
{
    pipii x;

    if (mid < l && mid < h)
        swap(mid, l);
    else if (h < l && h < mid)
        swap(h, l);
    if (h < mid)
        swap(h, mid);

    x.first = l;
    x.second.first = mid;
    x.second.second = h;
    return x;
}
pii cpb(int l, int h)
{
    if (l > h)
        swap(l, h);
    pii x;
    x.first = l;
    x.second = h;
    return x;
}
void func(int l, int h, int x, int &ct, int lv, int arr[], int n, vpipii &v, vpii &c);

bool find(vpipii v, pipii key)
{
    return find(v.begin(), v.end(), key) != v.end();
}
bool find(vpii c, pii key)
{
    return find(c.begin(), c.end(), key) != c.end();
}
void srt(int &l,int &mid,int &h){
    if (mid < l && mid < h)
        swap(mid, l);
    else if (h < l && h < mid)
        swap(h, l);
    if (h < mid)
        swap(h, mid);
}

void check(int x, int arr[], int n, int l, int h, vpipii &v, int &ct)
{
    int s = 0, e = n - 1, mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == x)
        {
            if (mid != h && mid != l && find(v, vpb(l, mid, h))==false)
            {
                v.push_back(vpb(l, h, mid));
                srt(l,mid,h);
                cout <<"("<< arr[l] << "," << arr[mid] << "," << arr[h] <<") ";
                ct++;
            }
            break;
        }
        else if (arr[mid] > x)
            e = mid - 1;
        else
            s = mid + 1;
    }
}

void func1(int l, int h, int x, int &ct, int arr[], int n, vpipii &v, vpii &c)
{
    if (arr[l] + arr[h] < x)
        l++;
    func(l, h, x, ct, x - arr[l] - arr[h], arr, n, v, c);
}
void func2(int l, int h, int x, int &ct, int arr[], int n, vpipii &v, vpii &c)
{
    if (arr[l] + arr[h] < x)
        h--;
    func(l, h, x, ct, x - arr[l] - arr[h], arr, n, v, c);
}
void func(int l, int h, int x, int &ct, int lv, int arr[], int n, vpipii &v, vpii &c)
{
    if (l < h)
    {
        if (arr[l] + arr[h] >= x)
            h--;
        else if (find(c, cpb(l, h)) == false)
        {
            check(lv, arr, n, l, h, v, ct);
            c.push_back(cpb(l, h));
        }
        func1(l, h, x, ct, arr, n, v, c);
        func2(l, h, x, ct, arr, n, v, c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //For faster I/O

    vpipii v;
    vpii c;
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    cout<<endl;
    int ct = 0;
    func(0, n - 1, x, ct, x - arr[0] - arr[n - 1], arr, n, v, c);
    if (ct == 0)
        cout << "-1"<<endl;
    else
    cout<<endl<<ct<<endl;
    return 0;
}