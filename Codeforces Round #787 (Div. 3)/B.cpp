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
    vector<pair<vector<ll>, vector<ll>>> cur(n);
    for (int i = 0; i<n; i++){
        for (int j = 0; j<i; j++){
            if (a[j] < a[i]) cur[i].ff.pb(j);
        }
        for (int j = i + 1; j<n; j++){
            if (a[j] > a[i]) cur[i].ss.pb(j);
        }
    }
    for (int i = 0; i<n; i++){
        cout << "Index: " << i << " " << sz(cur[i].ff) << " " << sz(cur[i].ss) << endl;
    }
    for (int i = 0; i<n; i++){
        for (int j = )
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