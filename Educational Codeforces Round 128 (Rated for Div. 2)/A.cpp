#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a, n) for (int i = a; i < n; i++)
#define Fd(n, a) for (int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define read(a) for (int i = 0; i<sz(a); i++) cin >> a[i]
const ll mod = 1e9 + 7;
vector<ll> BIT, BIT2;
void init(int n){
    BIT.resize(n + 1, 0);
    BIT2.resize(n + 1, 0);
}
ll getSum(int index)
{ 
    ll sum = 0;
    index = index + 1; 
    while (index>0) 
    { 
        sum += BIT[index]; 
        index -= index & (-index);
        cout << "Sum: " << sum << endl; 
    } 
    return sum; 
} 
ll getSum2(int index)
{ 
    ll sum = 0;
    index = index + 1; 
    while (index>0) 
    { 
        sum += BIT2[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void updateBIT(int n, int index, ll val) 
{ 
    index = index + 1; 
    while (index <= n) 
    { 
        BIT[index] = val; 
        index += index & (-index); 
    } 
} 
void updateBIT2(int n, int index, ll val) 
{ 
    index = index + 1; 
    while (index <= n) 
    { 
        BIT2[index] = val; 
        index += index & (-index); 
    } 
} 
ll sum(int x) 
{ 
    return (getSum(x) * x) - getSum2(x); 
} 
  
  
void updateRange(int n, 
                 ll val, int l, int r) 
{ 
    updateBIT(n,l,val); 
    updateBIT(n,r+1,-val); 
    updateBIT2(n,l,val*(l-1)); 
    updateBIT2(n,r+1,-val*r); 
} 
  
ll rangeSum(int l, int r) 
{ 
    return sum(r) - sum(l-1); 
} 
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    read(a);
    init(n);
    for (int i=0; i<n; i++)
        updateBIT(n, i, a[i]);
    for (int i=0; i<n; i++)
        updateBIT2(n, i, a[i]);
    for (int i = 0; i<q; i++){
        int t, idx;
        ll val;
        cin >> t;
        if (t == 1){
            cin >> idx >> val;
            updateRange(n, val, idx-1, idx-1);
            cout << rangeSum(1, n) << endl;
        }else {
            cin >> val;
            updateRange(n, val, 1, n);
            cout << rangeSum(1, n) << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}