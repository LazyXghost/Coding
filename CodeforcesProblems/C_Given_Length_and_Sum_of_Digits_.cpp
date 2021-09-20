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
#define forloop(i, a, b) for (int i = a; i <= b; i++)
#define forloopreverse(i, a, b) for (int i = a; i >= b; i--)
#define vectorloop(v, i) for(auto i = v.begin();i!=v.end();i++)
#define vectorloopreverse(v, i) for(auto i = v.end()-1;i!=v.begin()-1;i--)
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

// fill funtion can be used to fill anything with a value
// fill(arr, arr+n, {FILLING VALUE})
// fill(v.begin(),v.end(),{FILLING VALUE})
// vector<int> v({SIZE OF VECTOR}, {FILLING VALUE}) 
// vector<int> v({SIZE OF VECTOR})

string findResult(int len, int sum,string res = ""){
    int digitsreq = (int)((sum - 1) / 9) + 1;
    if (len < digitsreq || sum<0){
        return "-1";
    }

    int digit = 9;
    if (sum <= digit)
    {
        if (len == 1)
        {
            res += (char)(sum + 48);
            return res;
        }
        else
            digit = sum;
    }
    while(digit>=0){
        res += (char)(digit + 48);
        string temp = findResult(len-1, sum-digit,res);
        if(temp != "-1"){
            res = temp;
            break;
        }
        else{
            res.pop_back();
            digit--;
        }
    }
    if(res != "")
        return res;
    return "-1";
}
string getReversed(string res){
    reverse(res.begin(), res.end());
    int i = 1;
    while (res[0] == '0' && i<res.length())
    {
        if (res[i] != '0')
        {
            res[0] = '1';
            res[i] = (char)((int)(res[i]) - 1);
        }
        i++;
    }
    return res;
}

int main()
{
    FASTIO;

    int len,sum;
    input(len);
    input(sum);
    if(sum == 0){
        if(len == 1){
            print("0 0");
            return 0;
        }
        print("-1 -1");
        return 0;
    }

    string result = findResult(len,sum);
    if(result == "-1"){
        print("-1 -1");
        return 0;
    }
    print(getReversed(result));
    space;
    print(result);
    return 0;
}