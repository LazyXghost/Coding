#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

int cn1(int a[], int b[], int l, int h, int n1, int n2)
{
    if (a[n1 - 1] < b[0])
        if ((n1 + n2) / 2 > h + 1)
            return h + 1;
        else
            return (n1 + n2) / 2;
    else if (a[0] > b[n2 - 1])
        return 0;
    else
    {
        int no = (n1 + n2) / 2, no1, no2;
        while (l <= h)
        {
            no1 = ((l + h) / 2) + 1;
            no2 = no - no1;
            if (b[no2] < a[no1 - 1])
                h = no1 - 1;
            else if (a[no1] < b[no2 - 1])
                l = no1;
            else
                return no1;
        }
    }
    return 0;
}
float med(int a[], int b[], int no1, int no2)
{
    int ia = no1 - 1;
    int ib = no2 - 1;
    float med1, med2;
    if (a[ia] > b[ib])
        med1 = a[ia];
    else
        med1 = b[ib];
    if (a[no1] < b[no1])
        med2 = a[no1];
    else
        med2 = b[no2];
    return (med1 + med2) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    cin >> n1 >> n2;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
        cin >> a[i];
    for (int i = 0; i < n2; i++)
        cin >> b[i];
    int x = cn1(a, b, 0, n1 - 1, n1, n2);
    float median = med(a, b, x, ((n1 + n2) / 2) - x);
    cout << median << endl;
    return 0;
}