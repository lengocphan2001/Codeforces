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
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    read(a);
    map<ll, int> cur;
    for (int i = 0; i<n; i++){
        cur[a[i]]++;
    }
    int ans = 0;
    for (auto i: cur){
        if (i.second % 2 == 1){
            ans++;
        }
    }
    if (ans == 0){
        if (sz(cur) % 2 == 0) cout << sz(cur) << endl;
        else cout << sz(cur) - 1 << endl;
    }else{
        cout << ans + ((sz(cur) - ans) % 2 == 0? sz(cur) - ans: sz(cur) - ans - 1) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}