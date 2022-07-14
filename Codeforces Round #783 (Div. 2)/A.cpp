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
    vector<ll> dp1(n + 1, 0), dp2(n + 1, 0);
    for (int i = 1; i<=n; i++){
        dp1[i] = dp1[i - 1] + a[i - 1];
    }
    for (int i = n - 1; i>=0; i--){
        dp2[i] = dp2[i + 1] + a[i];
    }
    int ans = 0;
    reverse(all(dp2));
    for (int i = 1; i<=n; i++){
        auto it = lower_bound(all(dp2), dp1[i]);
        int pos = it - dp2.begin();
        if (pos > i){
            ans = max(ans, i + n - pos); 
        }
    }
    cout << ans << endl;
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