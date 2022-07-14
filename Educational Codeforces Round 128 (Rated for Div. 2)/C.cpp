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
struct BIT {
  long long M[N], A[N];
  BIT() {
    memset(M, 0, sizeof M);
    memset(A, 0, sizeof A);
  }
  void update(int i, long long mul, long long add) {
    while (i < N) {
      M[i] += mul;
      A[i] += add;
      i |= (i + 1);
    }
  }
  void upd(int l, int r, long long x) {
    update(l, x, -x * (l - 1));
    update(r, -x, x * r);
  }
  long long query(int i) {
    long long mul = 0, add = 0;
    int st = i;
    while (i >= 0) {
      mul += M[i];
      add += A[i];
      i = (i & (i + 1)) - 1;
    }
    return (mul * st + add);
  }
  long long query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
void solve()
{
    ll n;
    cin >> n;
    if (n % 2 == 1){
        cout << -1 << endl;
    }else{
        if ((n % 6) % 4 != 0 || (n % 4 != 0)){
            cout << -1 << endl;
        }else cout << n/6 + (n % 6)/4 << " " << n/4 << endl;    
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