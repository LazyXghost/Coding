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
#define val(x) (*x)

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

void sieve(int n, vector<bool> isPrime)
{
    forloop(i, 2, n)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
}

void findColoring(vi a){
    vector<bool> isPrime(1000+1, true);
    sieve(1000, isPrime);
    unordered_set<int> values;
    int k = 2;
    unordered_map<int,unordered_set<int>> connComponents;
    vector<int> primes;
    while(k!=999){
        if(isPrime[k]){
            unordered_set<int> singleConnComponent;
            vectorloop(a,i){
                if(val(i)%k == 0){
                    singleConnComponent.insert(val(i));
                    values.insert(val(i));
                }
            }
            if(singleConnComponent.size()>0){
                primes.push_back(k);
                connComponents[k] = singleConnComponent;
            }
        }
        k++;
    }
    vectorloop(connComponents, i){
        print(val(i).first);
        space;
        space;
        space;
        vectorloop(val(i).second, j){
            print(val(j));
            space;
        }
        newline;
    }
    values.clear();
    print(primes.size());
    newline;
    vectorloop(primes, i)
    {
        // val(i) gives prime no
        // cci is conn component of that prime no
        unordered_set<int> cci = connComponents[val(i)];
        auto lastj = cci.begin();
        vectorloop(cci, j)
        {
            // val(j) gives value in conn component
            auto k = i + 1;
            vector<int> ccierase;
            // val(k) gives prime no greater than val(i)
            while (k != primes.end())
            {
                unordered_set<int> cck = connComponents[val(k)];
                if (cck.find(val(j)) != cck.end())
                {
                    ccierase.push_back(val(j));
                    break;
                }
                k++;
            }
            print("Size of ccierase is ");
            print(ccierase.size());
            newline;
            vectorloop(ccierase,m){
                print("Want to erase "<<val(m));
                newline;
                print("Value in cii is ");
                print(val(cci.find(val(m))));
                newline;
                vectorloop(ccierase, z){
                    print(val(z));
                    space;
                }
                newline;
                cci.erase(val(m));
                j = lastj;
            }
            print("got out");
            newline;
            lastj = j;
        }
        if(cci.size()==0){
            print("cci size is zero");
            newline;
            connComponents.erase(connComponents.find(val(i)));
            i--;
        }
    }
    print(connComponents.size());
    newline;
}

int main()
{
    // FASTIO;
    tests(t){
        int n;
        input(n);
        vi a;
        forloop(i,0,n-1){
            int x;
            input(x);
            a.push_back(x);
        }
        findColoring(a);
    }
    return 0;
}